## TD 1
### Q1 
```console
$ ros2 topic pub -r N (Hz frequency) /topic_name std_msgs/String "whatever you want"
```
For example, 10Hz frequency, topic named "The Roof" :
```console
$ ros2 topic pub -r 10 /TheRoof std_msgs/strings "Je passe enfin des marrons"
```
### Q2
```console
$ ros2 interface show std_msgs/msg/Float64
```
```console
$ ros2 interface show sensor_msgs/srv/Imu
```
```console
$ ros2 interface show sensor_msgs/srv/
```
