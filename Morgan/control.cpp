extern "C" {
  #include "roboticscape.h"
  #include "rc_usefulincludes.h"
}

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

#define outPin 112 //P9_30

int main(int argc, char *argv[])
{
    rc_initialize();
    rc_set_pinmux_mode(outPin, PINMUX_GPIO);
    rc_gpio_export(outPin);
    rc_gpio_set_dir(outPin, OUTPUT_PIN);

    int freq = 15*1000; // PWM frequency
    rc_set_pinmux_mode(3,PINMUX_PWM);
    rc_pwm_init(0,freq);
    float entry = 0.0; // PWM duty cycle
    int dir = 0; // Direction of motor
    string fileName = argv[1];

    struct timespec start, finish;
	double elapsedTime;
    const int size = 200000; // Array size
    double pos[size]; // Array of position values
    double vel[size]; // Array of velocity values
	double time[size+1]; // Array of times
	time[0] = 0; // Start time
	int i = 0; // Int for indexing

	// Initialize encoders
    rc_set_encoder_pos(3, 0);
    double currentEncoderValue = 0.0;
    double previousEncoderValue = 0.0;
    const int countsPerRevolution = 512*128*4;
    const int degreesPerRevolution = 360;

	// Control parameters
	double desiredValue = 400; // Desired position in degrees
    double error = desiredValue - currentEncoderValue;
    double prevError = error; // Previous error for derivative action
    double sum = 0; // Error sum for integral action
    double difference = 0; // Error difference for derivative action
    double Kp = 0.9; // Proportional gain
    double Kd = 0.0; // Derivative gain
    double Ki = 0.0; // Integral gain

    while(entry != -1.0 && i < size){
    	clock_gettime(CLOCK_MONOTONIC, &start);
        currentEncoderValue = rc_get_encoder_pos(3);
        currentEncoderValue = currentEncoderValue*degreesPerRevolution/countsPerRevolution;
        rc_pwm_set_duty(0,'B', entry);
        rc_gpio_set_value_mmap(outPin, dir);
            
        pos[i] = currentEncoderValue;
        vel[i] = (currentEncoderValue - previousEncoderValue)/elapsedTime;

		prevError = error;
		error = desiredValue - currentEncoderValue;
		sum += error;
		difference = (error-prevError)/elapsedTime;

        entry = Kp*error + Ki*sum*elapsedTime + Kd*difference; // PWM with PID
                
        if (entry < 0) {
			entry = -1*entry;
            dir = 1;
		} else {
			dir = 0;
		}

		if (entry > 0.9) {
			entry = 0.9;
		}

		if (entry < 0.1 && error > 5) {
			entry = 0.1;
		}

        previousEncoderValue = currentEncoderValue;
        i++;
        
        // Time
        clock_gettime(CLOCK_MONOTONIC, &finish);
		elapsedTime = (finish.tv_sec - start.tv_sec);
		elapsedTime += (finish.tv_nsec - start.tv_nsec)/ 1000000000.0;
		time[i+1] = time[i] + elapsedTime;
    }
    
	rc_pwm_set_duty(0, 'B', 0.0); // Set PWM to 0 after loop
    rc_pwm_close(0); 
    
    // Save position, velocity, time data
    ofstream data (fileName.c_str());
  	if (data.is_open())
  	{
		for(int count = 0; count < size; count ++){
			data << pos[count] << "," ;
		}
		for(int count = 0; count < size; count ++){
			data << vel[count] << ",";
		}
		for(int count = 0; count < size; count ++){
            data << time[count] << ",";
        }
		data.close();
  	}
  	else cout << "Unable to open file";
    return 0;
}
