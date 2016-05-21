extern "C" {
  #include <roboticscape.h>
  #include <rc_usefulincludes.h>
}


#include <stdio.h>

int main(int argc, char *argv[])
{
        rc_initialize();
        int freq = 15*1000;
        rc_set_pinmux_mode(GPS_HEADER_PIN_4,PINMUX_PWM);
        rc_pwm_init(0,freq);
        float entry = atof(argv[1]);
	rc_pwm_set_duty(0,'B', entry);
        while(rc_get_state() != EXITING){
        }
	rc_pwm_set_duty(0, 'B', 0);
        return 0;
}


