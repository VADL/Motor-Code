extern "C" {
  #include "roboticscape.h"
  #include "rc_usefulincludes.h"
}

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <time.h>


//this code needs to be tested before we actually use it please
int main(int argc, char *argv[])
{
    rc_initialize();
    std::string fname = "~/IMU_Log.txt";
    rc_imu_data_t *ptr = new rc_imu_data_t;
    
    
    bool initSucess = rc_initialize_imu_dmp(ptr, rc_get_default_imu_config());
    int measureCount = 100000;
    ofstream data(fname);
    
    
  	if (data.is_open()&&initSucess)
  	{
        data << "logging begin"<<std::endl;
        for(int i = 0; i<measureCount;++i) {
            data << "acceleration data" << std::endl
            data <<  ptr->accel[0] <<std::endl;
            data <<  ptr->accel[1] <<std::endl;
            data <<  ptr->accel[2] <<std::endl; // units of m/s^2
            data << "gyro data"    <<std::endl
            data <<  ptr->gyro[0]  <<std::endl;
            data <<  ptr->gyro[1]  <<std::endl;
            data <<  ptr->gyro[2]  <<std::endl;// units of degrees/s
            data << "temp data"    <<std::endl /// units of degrees Celsius
            data <<  ptr -> temp;  <<std::endl <<std::endl;
        }
        rc_power_off_imu();
  	}
  	else cout << "Unable to open file";
    return 0;
}