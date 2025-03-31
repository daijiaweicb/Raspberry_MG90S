cmake_minimum_required(VERSION 3.10)
project(MG90S_PWM_Demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(servo_demo demo.cpp pwm.cpp)

install(TARGETS servo_demo RUNTIME DESTINATION bin)