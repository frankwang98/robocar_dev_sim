cmake_minimum_required(VERSION 3.0.2)
project(robocar_gazebo)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  geometry_msgs
  nav_msgs
  tf
  gazebo_ros
  msg_common
)

find_package(gazebo REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS 
  roscpp 
  std_msgs 
  sensor_msgs 
  geometry_msgs 
  nav_msgs 
  tf 
  gazebo_ros
  msg_common
  DEPENDS GAZEBO
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
)

link_directories(${GAZEBO_LIBRARY_DIRS})

add_executable(robocar_gazebo src/robocar_gazebo.cpp)
add_dependencies(robocar_gazebo ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(robocar_gazebo ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

# install
# install(TARGETS robocar_gazebo
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
# )

# install(DIRECTORY launch models rviz worlds
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )