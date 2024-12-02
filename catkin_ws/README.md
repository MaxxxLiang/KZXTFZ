## 1126作业 RRT*算法实现

### 如何运行代码

切换到工作空间目录下，在终端运行如下命令`bash cleanNbuild.sh`

该脚本会清除之前编译的文件并重新编译

编译成功后，在终端输入

```
source devel/setup.bash

roslaunch path_finder rviz.launch
```

即可看到运行结果

### 简要的算法流程

主要函数为bool rrt_star(const Eigen::Vector3d &s, const Eigen::Vector3d &g)
