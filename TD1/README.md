## TD 1
### Question 1 
```console
$ ros2 topic pub -r N (Hz frequency) /topic_name std_msgs/String "data: whatever you want"
```
For example, 10Hz frequency, topic named "The Roof" :
```console
$ ros2 topic pub -r 10 /TheRoof std_msgs/String "data: Je passe enfin des marrons"
```
### Question 2
```console
$ ros2 interface show std_msgs/msg/Float64
```
```console
$ ros2 interface show sensor_msgs/srv/Imu
```
```console
$ ros2 interface show std_srvs/srv/Trigger
```
### Question 3
```console
$ ros2 topic pub -r 1 /cap std_msgs/Float64 "data: 90"
```
### Question 4/5
This command counts all the active nodes (including the hidden ones)
```console
$ ros2 node list -a | wc -l
```
### Question 6
```console
$ sudo apt install tree
$ tree
```
![tree]("tree1.png")

### Question 7
Same command : 
```console
$ tree
```
![tree]("tree2.png")

