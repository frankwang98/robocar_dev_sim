cmake_minimum_required(VERSION 3.0.2)
project(info_router)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## System dependencies are found with CMake's conventions
find_package(Protobuf REQUIRED)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lprotobuf  -std=c++11  -lpthread -lboost_system")  # -fopenmp

## header directories
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(/usr/local/include)  

## Uncomment this if the package has a setup.py. This macro ensures
# catkin_python_setup()

## Declare ROS messages, services and actions ##
## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

## Declare ROS dynamic reconfigure parameters ##
## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

## catkin specific configuration ##
catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
)

## Build ##
## Specify additional locations of header files
include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(c_info_router src/c_info_router.cpp)

## Add cmake target dependencies of the library
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

# # 设置源文件和目标文件路径
# set(SOURCE_RDS ${CMAKE_CURRENT_SOURCE_DIR}/src/mine_rds.pb.h)
# set(TARGET_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# # proto 生成 C++ 代码的自定义命令
# add_custom_command(
#     OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/include/mine_rds.pb.h
#            ${CMAKE_CURRENT_SOURCE_DIR}/src/mine_rds.pb.cc    
#     COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
#             --proto_path=${CMAKE_CURRENT_SOURCE_DIR}/src
#             --cpp_out=${CMAKE_CURRENT_SOURCE_DIR}/src
#             ${PROTO_RDS}
#     COMMAND ${CMAKE_COMMAND} -E copy ${SOURCE_RDS} ${TARGET_DIR}
#     COMMAND ${CMAKE_COMMAND} -E remove ${SOURCE_RDS}
#     DEPENDS ${PROTO_RDS}
#     COMMENT "Generating C++ code from proto file"
#     COMMENT "Moving file to target directory"
# )

## Declare a C++ executable
add_executable(${PROJECT_NAME} src/n_info_router.cpp
                              src/c_cockpit_router.cpp
                              src/config_io.cpp
                              src/easylogging++.cc
                              src/openssl_code.cc
                              src/utils.cpp
                              src/mine_rds.pb.cc
)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
                      ${catkin_LIBRARIES}  
                      ${PROTOBUF_LIBRARIES}
                      -luuid
                      -lssl
                      -lcrypto
)

## Install ##
## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# catkin_install_python(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark libraries for installation
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )
