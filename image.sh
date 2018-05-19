#!/usr/bin/env bash

rosparam set /usb_cam/video_device /dev/video1
rosparam set /usb_cam/image_width 1920
rosparam set /usb_cam/image_height 1080

rosrun usb_cam usb_cam_node &

rosrun image_view image_view image:=/usb_cam/image_raw

