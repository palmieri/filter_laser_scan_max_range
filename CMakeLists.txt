  cmake_minimum_required(VERSION 2.8.3)
project(filter_laser_scan_max_range)

##############################################################################
# Find dependencies
##############################################################################

set(THIS_PACKAGE_ROS_DEPS
  class_loader
  pluginlib
  sensor_msgs
  filters
)

find_package(catkin REQUIRED COMPONENTS ${THIS_PACKAGE_ROS_DEPS})

include_directories(include ${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})
message("filter_laser_scan_max_range catkin_LIBRARY_DIRS: " ${catkin_LIBRARY_DIRS})

##############################################################################
# Define package
##############################################################################

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS ${THIS_PACKAGE_ROS_DEPS}
)

add_library(filter_laser_scan_max_range src/filter_laser_scan_max_range.cpp)

add_dependencies(filter_laser_scan_max_range ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(filter_laser_scan_max_range ${catkin_LIBRARIES})

##############################################################################
# Install
##############################################################################

install(TARGETS filter_laser_scan_max_range
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


