#!/bin/bash

export ROBOCAR_MODEL=burger # burger waffle waffle_pi
source devel/setup.bash
roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=gmapping
# rosrun map_server map_saver -f ./map

# sudo apt install ros-noetic-openslam-gmapping
# sudo apt install ros-noetic-map-server --no-install-suggests