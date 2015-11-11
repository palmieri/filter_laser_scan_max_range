# filter_laser_scan_max_range
filter_laser_scan_max_range, it filters the LaserScan message to replace scans having max_range value with (max_range - eps)


### Motivation 
This filters helps the costmap2D to clear obstacles. During the clearing scans to which are assigned the maximum value of the range are not correctly cleared (see http://ros-users.122217.n3.nabble.com/Clearing-old-obstacles-from-costmap-td1920291.html). The filter substitutes the  maximum range value with a slightly lower one.

### Requirements
* ROS
* ros-hydro-navigation or ros-indigo-navigation
* ros-hydro-laser-filters or ros-indigo-laser-filters
* ros-filters
* C++11 compiler


### Installation

Clone the package into you catkin workspace
- `cd [workspace]/src`
- `git clone https://github.com/palmieri/filter_laser_scan_max_range.git`
- `cd ../`
- `catkin_make` or `catkin build`

### Usage
- For a tutorial on how to use a laser filter please refer to http://wiki.ros.org/laser_filters
### Developers
Any contribution to the software is welcome. Contact the current developers for any info: 
* Luigi Palmieri (https://github.com/palmieri, palmieri(at)informatik.uni-freiburg.de)


