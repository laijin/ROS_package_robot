# ROS_package_robot
##这是我自己修改ROS代码后，这只是第一个简单的tuetle运动代码,这里需要自己建立一个ros的工作空间，然后把这些包放到src里面

###其中learning_communication这个包里面有些是暂时用不到的，等之后分享的包里，会介绍这几个包的用途，其实就是一些通过人脸或者语音来控制小车运动的代码

* learning_communication src中：
  * talker.cpp和listener.cpp是简单的ROS入门例程代码，主要是测试话题编程。在这之前或之后需要配置CMakeLists.txt.最后只需要rosrun learning_communication talker以及rosrun learning_communication listener（rosmsg show Person可以查看自定义Person.msg中的消息）
  * server.cpp和client.cpp是简单的测试服务编程的例程，在这步中需要配置工作空间中的CMakeLists.txt。运行rosrun learning_communication server和rosrun learning_communication client 3 5（其中后面两个数字可以自己定义）
* learning_communication src(action)中:(这是关于动作编程的例程，在我看来动作编程其实跟其他两个类型差别不是很大，基本操作都类似)
  * 这个例程主要是测试一个洗盘子的过程，修改CMakeLists.txt.运行rosrun learning_communication DoDishes_client和rosrun learning_communication DoDishes_server
* learning_tf
  * 这个也是ROS的基本例程，主要是测试tf的功能.运行roslaunch learning_tf start_demo)with_listener.launch


