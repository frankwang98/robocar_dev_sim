#!/bin/bash

export ROBOCAR_MODEL=burger # burger waffle waffle_pi
source devel/setup.bash

#roslaunch robocar_gazebo robocar_world.launch

# 将model复制到系统目录
# mkdir -p ~/.gazebo/models/
# cp -r  models/ ~/.gazebo/models/

# 空白地图
# roslaunch robocar_gazebo robocar_empty_world.launch
# 复杂地图
# roslaunch robocar_gazebo robocar_world.launch
roslaunch robocar_gazebo robocar_house.launch # 启动卡顿
# 仿真自动跑
# roslaunch robocar_gazebo robocar_simulation.launch
# rviz可视化
# roslaunch robocar_gazebo robocar_gazebo_rviz.launch
