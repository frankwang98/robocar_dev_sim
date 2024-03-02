#!/bin/bash

export ROBOCAR_MODEL=burger # burger waffle waffle_pi
source devel/setup.bash
roslaunch turtlebot3_navigation turtlebot3_navigation.launch #map_file:=./map.yaml

# rostopic echo /cmd_vel

# sudo apt install ros-noetic-amcl ros-noetic-move-base ros-noetic-dwa-local-planner
