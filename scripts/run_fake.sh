#!/bin/bash

export ROBOCAR_MODEL=burger # burger waffle waffle_pi
source devel/setup.bash
# rosrun robocar_fake robocar_fake
roslaunch robocar_fake robocar_fake.launch
