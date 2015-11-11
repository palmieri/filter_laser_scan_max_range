# filter_laser_scan_max_range
filter_laser_scan_max_range, it filters the LaserScan message to replace scans having max_range value with (max_range - eps)

This filters helps the costmap2D to clear obstacles (see http://ros-users.122217.n3.nabble.com/Clearing-old-obstacles-from-costmap-td1920291.html).


