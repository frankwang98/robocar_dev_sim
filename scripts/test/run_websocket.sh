#!/bin/bash

export ROBOCAR_MODEL=burger # burger waffle waffle_pi
source devel/setup.bash
roslaunch rosbridge_server rosbridge_websocket.launch

# roslaunch rosbridge_server rosbridge_udp.launch

# roslaunch rosbridge_server rosbridge_tcp.launch

# sudo apt install ros-noetic-rosauth
# pip install tornado bson pymongo -i https://pypi.tuna.tsinghua.edu.cn/simple