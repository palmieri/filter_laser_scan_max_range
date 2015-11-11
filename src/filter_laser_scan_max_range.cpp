/*********************************************************************
*
* Software License Agreement (BSD License)
*
*  Copyright (c) 2015, University of Freiburg
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of Willow Garage, Inc. nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
* Author: Luigi Palmieri <palmieri@cs.uni-freiburg.de>
*********************************************************************/
#include <filter_laser_scan_max_range/filter_laser_scan_max_range.h>

#include <pluginlib/class_list_macros.h>




namespace filter_laser_scan_max_range 
{

	  FilterLaserScanMaxRange::FilterLaserScanMaxRange(){

	  	ROS_INFO("Filter FilterLaserScanMaxRange on!");
	  }

	  FilterLaserScanMaxRange::~FilterLaserScanMaxRange(){


	  }


      bool FilterLaserScanMaxRange::configure()
      {
        return true;
      }



      bool FilterLaserScanMaxRange::update(const sensor_msgs::LaserScan& input_scan, sensor_msgs::LaserScan& scan_to_filter)
      {
        scan_to_filter = input_scan;

        for(unsigned int i = 0; i < scan_to_filter.ranges.size(); ++i)
        {
          //set to just below max range if its greater than max range
          if(scan_to_filter.ranges[i] >= scan_to_filter.range_max || scan_to_filter.ranges[i] <= scan_to_filter.range_min)
            scan_to_filter.ranges[i] = scan_to_filter.range_max - 1e-4;
        }

        return true;
      }


}



PLUGINLIB_EXPORT_CLASS(filter_laser_scan_max_range::FilterLaserScanMaxRange, filters::FilterBase<sensor_msgs::LaserScan>)
