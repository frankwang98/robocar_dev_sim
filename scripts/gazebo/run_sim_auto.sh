#!/bin/bash

export ROBOCAR_MODEL=burger # burger waffle waffle_pi
source devel/setup.bash

# 仿真自动跑
roslaunch robocar_gazebo robocar_simulation.launch
