# kadai2
# 概要
rosのturtlesimをPS5用のコントローラDUALSENCEで動かすノードです  
前提としてros-任意のバージョン-joyとros-任意のバージョン-joystick-drivers,ros-任意のバージョン-turtlesimのインストールが必要です 
# 実行方法
catkin_make後,DUALSENCEを有線で接続しroslaunch joykame turtle.launchと入力することでDUALSENCEでturtlesimを動かせるようになります
# 操作方法  
左スティック：移動  
L2：左回転  
Xボタン:線消去  
# 引用
https://github.com/project-srs/ros_lecture/blob/master/basic_lecture/src/basic_twist_publisher.cpp  
https://github.com/project-srs/ros_lecture/blob/master/LICENSE  
