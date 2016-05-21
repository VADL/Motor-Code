extern "C" {
#include "roboticscape.h"
#include "rc_usefulincludes.h"
}

#include <string>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

//this code needs to be tested before we actually use it please
int main(int argc, char *argv[])
{
  if(rc_initialize() != 0){
    std::cerr << "Failed to initize\n";
  }
  std::string fname = "/home/root/Motor-Code/IMU_Log.txt";
  rc_imu_data_t imu_data;
    



  rc_imu_config_t config = rc_default_imu_config();
    
  if(rc_initialize_imu(&imu_data, config) != 0){
    std::cerr << "Failed to init imu\n";
  }
  //    int measureCount = 10000;
  //    ofstream data(fname.c_str());

  //	data.open(fname.c_str());

  //    if (!data)
  //  	{
  //        data << "logging begin"<<std::endl;
  //        for(int i = 0; i<measureCount;++i) {
  //            data << "acceleration data" << std::endl;
  //            data <<  ptr->accel[0] <<std::endl;
  //            data <<  ptr->accel[1] <<std::endl;
  //            data <<  ptr->accel[2] <<std::endl; // units of m/s^2
  //            data << "gyro data"    <<std::endl;
  //            data <<  ptr->gyro[0]  <<std::endl;
  //            data <<  ptr->gyro[1]  <<std::endl;
  //            data <<  ptr->gyro[2]  <<std::endl;// units of degrees/s
  //            data << "temp data"    <<std::endl; /// units of degrees Celsius
  //            data <<  ptr -> temp   <<std::endl;
  //	    data << std::endl;
  //        }
  //        rc_power_off_imu();
  //  	}
  //  	else cout << "Unable to open file";

  while (rc_get_state() != EXITING){

    rc_read_accel_data(&imu_data);
    std::cout << "acceleration data" << std::endl;
    std::cout << "x: "<< imu_data.accel[0] <<std::endl;
    std::cout << "y: "<< imu_data.accel[1] <<std::endl;
    std::cout << "z: "<< imu_data.accel[2] <<std::endl;
    usleep(1000000);
  }
  return 0;
}
