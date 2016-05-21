extern "C" {
#include "roboticscape.h"
#include "rc_usefulincludes.h"
}

#include <string>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <errno.h>

//this code needs to be tested before we actually use it please
int main(int argc, char *argv[])
{
  if(rc_initialize() != 0){
    std::cerr << "Failed to initize\n";
  }
  std::string fname = "../IMU_Log.txt";
  rc_imu_data_t imu_data;
    



  rc_imu_config_t config = rc_default_imu_config();
    
  if(rc_initialize_imu(&imu_data, config) != 0){
    std::cerr << "Failed to init imu\n";
  }
    
    
   std::ofstream data;
   try{data.open(fname.c_str());}
   catch (std::ios_base::failure& e){
   std::cout <<strerror(errno) <<'\n';
   }
  

   if(!data.is_open()){
   std::cout<<"log failed to init ;("<<std::endl;
   std::cout<<strerror(errno)<<std::endl;
 return 0;  
}
//  struct timespec start, finish;
 // clock_gettime(CLOCK_MONOTONIC, &start);
  double elap = 0.0;
  while (rc_get_state() != EXITING&&elap<7200.0){

    rc_read_accel_data(&imu_data);
    rc_read_gyro_data(&imu_data);

//    std::cout <<"z: " <<imu_data.accel[2] << std::endl;
    data << "acceleration data" << std::endl;
    data << "x: "<< imu_data.accel[0] <<std::endl;
    data << "y: "<< imu_data.accel[1] <<std::endl;
    data << "z: "<< imu_data.accel[2] <<std::endl;
    data << "acceleration data" << std::endl;
    data << "roll: "<< imu_data.gyro[0] <<std::endl;
    data << "pitch: "<< imu_data.gyro[1] <<std::endl;
    data << "yaw: "<< imu_data.gyro[2] <<std::endl;
    data << "time: "<<elap<<std::endl;

    data <<std::endl<<std::endl;
    usleep(10);
 //  clock_gettime(CLOCK_MONOTONIC,&finish);
   elap = rc_nanos_since_boot()/1000000000;
  }
    data.close();
  return 0;
}
