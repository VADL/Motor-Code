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
    
    
    fstream data(fname.c_str());



  while (rc_get_state() != EXITING){

    rc_read_accel_data(&imu_data);
    rc_read_gyro_data(&imu_data);
    data << "acceleration data" << std::endl;
    data << "x: "<< imu_data.accel[0] <<std::endl;
    data << "y: "<< imu_data.accel[1] <<std::endl;
    data << "z: "<< imu_data.accel[2] <<std::endl;
    data << "acceleration data" << std::endl;
    data << "roll: "<< imu_data.gyro[0] <<std::endl;
    data << "pitch: "<< imu_data.gyro[1] <<std::endl;
    data << "yaw: "<< imu_data.gyro[2] <<std::endl;
    data <<std::endl<<std::endl;
    usleep(1000);
  }
    data.close();
  return 0;
}
