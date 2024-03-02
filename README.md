# robocar_dev_sim
robocar_dev_sim机器人/自动驾驶仿真学习，算法验证，参考turtlebot等开源算法

## 实现功能
1. rviz / gazebo机器人仿真，可自定义机器人模型
2. 机器人状态信息获取，包括位置，速度，加速度等；实现键盘控制机器人运动
3. 实现PID等控制算法，实现机器人运动控制
4. 实现混合A*等规划算法，实现机器人路径规划
5. 实现激光雷达感知信息获取并进行SLAM建图，实现机器人实时定位
6. 实现感知与机器人规控结合，实现机器人自主导航与避障等功能

## 编译运行
```bash
bash build.sh
bash scripts/run_fake.sh
bash clean.sh
```

## 参考
- turtlebot3
- ros_motion_planning
