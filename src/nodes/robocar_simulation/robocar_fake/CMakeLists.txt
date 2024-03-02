cmake_minimum_required(VERSION 3.0.2)
project(robocar_fake)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  geometry_msgs
  nav_msgs
  tf
  msg_common
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS 
  roscpp 
  std_msgs 
  sensor_msgs 
  geometry_msgs 
  nav_msgs 
  tf 
  msg_common
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(robocar_fake src/robocar_fake.cpp)

add_dependencies(robocar_fake ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(robocar_fake ${catkin_LIBRARIES})

# install
# install(TARGETS robocar_fake
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
# )

# install(DIRECTORY launch rviz
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )