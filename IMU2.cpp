extern "C" {
  #include "roboticscape.h"
  #include "rc_usefulincludes.h"
}

#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

//this code needs to be tested before we actually use it please
int main(int argc, char *argv[])
{
    rc_initialize();
    std::string fname = "~/Motor-Code/IMU_Log.txt";
    rc_imu_data_t *ptr = new rc_imu_data_t;
    



   // rc_imu_config config = rc_get_default_imu_config();
    
    bool initSucess = true;
   // rc_initialize_imu(ptr, config);
    int measureCount = 10000;
    ofstream data(fname.c_str());

//	data.open(fname.c_str());

      	if (!data)
  	{
        data << "logging begin"<<std::endl;
        for(int i = 0; i<measureCount;++i) {
            data << "acceleration data" << std::endl;
            data <<  ptr->accel[0] <<std::endl;
            data <<  ptr->accel[1] <<std::endl;
            data <<  ptr->accel[2] <<std::endl; // units of m/s^2
            data << "gyro data"    <<std::endl;
            data <<  ptr->gyro[0]  <<std::endl;
            data <<  ptr->gyro[1]  <<std::endl;
            data <<  ptr->gyro[2]  <<std::endl;// units of degrees/s
            data << "temp data"    <<std::endl; /// units of degrees Celsius
            data <<  ptr -> temp   <<std::endl;
	    data << std::endl;
        }
        rc_power_off_imu();
  	}
  	else cout << "Unable to open file";
    return 0;
}
