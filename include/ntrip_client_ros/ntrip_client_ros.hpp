//
// Created by farukbaykara on 04.05.2023.
//

#ifndef NTRIP_CLIENT_ROS_NTRIP_CLIENT_ROS_H
#define NTRIP_CLIENT_ROS_NTRIP_CLIENT_ROS_H


#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <sstream>
#include <cstring>


#include <ntrip/ntrip_client.h>

#include <rclcpp/rclcpp.hpp>
#include "nmea_msgs/msg/gpgga.h"
#include "mavros_msgs/msg/rtcm.hpp"

#include "AsyncSerial.h"

class NtripClientRos: public rclcpp::Node
{
public:

  NtripClientRos();


private:

  bool NtripClientStart();

  void ReadParameters();

  //Parameters
  std::string m_serial_port_;
  long m_serial_baud_rate_;
  std::string m_ntrip_ip_;
  std::string m_ntrip_password_;
  std::string m_ntrip_username_;
  std::string m_ntrip_mountpoint_;
  long m_ntrip_port_;
  bool m_publish_rtcm_;
  bool m_debug_;
  double m_ntrip_location_lat;
  double m_ntrip_location_lon;

  libntrip::NtripClient m_ntripClient_;

  uint8_t m_ntripStatus_;


};



#endif  // NTRIP_CLIENT_ROS_NTRIP_CLIENT_ROS_H
