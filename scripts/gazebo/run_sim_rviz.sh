#!/bin/bash

export ROBOCAR_MODEL=burger # burger waffle waffle_pi
source devel/setup.bash

# rviz可视化
roslaunch robocar_gazebo robocar_gazebo_rviz.launch
