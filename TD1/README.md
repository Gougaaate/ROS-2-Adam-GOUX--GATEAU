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
ros2 topic pub -r 1 /cap std_msgs/Float64 "data: 90"
```
### Question 4/5
This command counts all the active nodes (including the hidden ones)
```console
ros2 node list -a | wc -l
```
### Question 6
```console
$ sudo apt install tree
$ tree
```
It shows this, which looks good in your shell.... 
├── build
│   └── COLCON_IGNORE
├── install
│   ├── COLCON_IGNORE
│   ├── local_setup.bash
│   ├── local_setup.ps1
│   ├── local_setup.sh
│   ├── _local_setup_util_ps1.py
│   ├── _local_setup_util_sh.py
│   ├── local_setup.zsh
│   ├── setup.bash
│   ├── setup.ps1
│   ├── setup.sh
│   └── setup.zsh
├── log
│   ├── build_2023-03-01_16-32-29
│   │   ├── events.log
│   │   └── logger_all.log
│   ├── COLCON_IGNORE
│   ├── latest -> latest_build
│   └── latest_build -> build_2023-03-01_16-32-29
├── README.md
├── src
└── TD1
└── README.md
