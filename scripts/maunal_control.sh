#!/bin/bash

export ROBOCAR_MODEL=burger # burger waffle waffle_pi
source devel/setup.bash
rosrun teleop_twist_keyboard teleop_twist_keyboard

# rostopic pub
# rostopic pub /cmd_vel geometry_msgs/Twist "linear:
#   x: 0.1
#   y: 0.0
#   z: 0.0
# angular:
#   x: 0.0
#   y: 0.0
#   z: 0.5"