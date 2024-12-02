## 1126作业 RRT*算法实现

### 如何运行代码

切换到工作空间目录下，在终端运行如下命令 `bash cleanNbuild.sh`

该脚本会清除之前编译的文件并重新编译

编译成功后，在终端输入

```
source devel/setup.bash

roslaunch path_finder rviz.launch
```

即可看到运行结果

### 简要的算法流程

主要函数为bool rrt_star(const Eigen::Vector3d &s, const Eigen::Vector3d &g)

输入参数为 起始点和目标点

算法流程如下：

1. 随机采样：在搜索空间中随机选取一个新的点q_rand,作为扩展树的候选方向。
2. 节点选择：在树中找到一个已有节点q_near，使得它与新采样点q_rand之间的距离最小。
3. 节点扩展：从q_near沿着q_rand的方向创建一个新节点q_new，这个新节点是向目标方向的一步扩展。
4. 成本计算：计算从起点到q_new的路径成本，即累计成本
5. **选择父节点：在q_new附近找到一组节点Q_near，并尝试将其中某些节点作为q_new的父节点，如果这样可以减少到达q_new的成本。**
6. **更新树：如果通过q_new可以降低Q_near中其他节点的成本，那么重新连接这些节点，使q_new成为它们的父节点。也成为剪枝**

其中对比RRT算法，主要多了5和6两个步骤，对应的代码如下:

第5步，选择代价最小的父节点，此处使用的是全局路径代价最小作为依据

```
        // TODO Choose a parent according to potential cost-from-start values
        // ! Hints:
        // !  1. Use map_ptr_->isSegmentValid(p1, p2) to check line edge validity;
        // !  2. Default parent is [nearest_node];
        // !  3. Store your chosen parent-node-pointer, the according cost-from-parent and cost-from-start
        // !     in [min_node], [cost_from_p], and [min_dist_from_start], respectively;
        // !  4. [Optional] You can sort the potential parents first in increasing order by cost-from-start value;
        // !  5. [Optional] You can store the collison-checking results for later usage in the Rewire procedure.
        // ! Implement your own code inside the following loop
        for (auto &curr_node : neighbour_nodes)
        {
            if(map_ptr_->isSegmentValid(x_new,curr_node->x)){//检测节点是否有效
                //检测临近节点的cost 进行对比 这里使用全局路径代价作为依据
                double dist = calDist(curr_node->x,x_new);
                double tmp_Cost_from_start = curr_node->cost_from_start+dist;
                if( tmp_Cost_from_start < min_dist_from_start){//如果全局路径代价更小，更换父节点
                    min_node = curr_node;
                    min_dist_from_start = tmp_Cost_from_start;
                    cost_from_p = dist;
                }
            }
        }
        // ! Implement your own code inside the above loop
```

第6步，进行剪枝操作 在//! ------- ------!//中的是主要部分

```
        /* 3.rewire */
        // TODO Rewire according to potential cost-from-start values
        // ! Hints:
        // !  1. Use map_ptr_->isSegmentValid(p1, p2) to check line edge validity;
        // !  2. Use changeNodeParent(node, parent, cost_from_parent) to change a node's parent;
        // !  3. the variable [new_node] is the pointer of X_new;
        // !  4. [Optional] You can test whether the node is promising before checking edge collison.
        // ! Implement your own code between the dash lines [--------------] in the following loop
        for (auto &curr_node : neighbour_nodes)
        {
            double best_cost_before_rewire = goal_node_->cost_from_start;
            // ! -------------------------------------
            if(map_ptr_->isSegmentValid(curr_node->x,new_node->x)){//检测节点是否有效
                double dist = calDist(curr_node->x,x_new);//计算新节点到临近节点的cost
                double tmp_Cost_from_start = new_node->cost_from_start+dist;//将新节点作为父节点时的代价
                if( tmp_Cost_from_start < curr_node->cost_from_start){//如果全局路径代价更小，进行剪枝
                    // curr_node->parent = new_node;
                    // curr_node->cost_from_start = tmp_Cost_from_start;
                    // curr_node->cost_from_parent = dist;
                    // curr_node->children=new_node->children;
                    // curr_node->children.push_back(new_node);
                    //上面注释掉的代码和changeNodeParent的效果应该是一样的
                    changeNodeParent(curr_node,new_node,dist);
                }
            }
            // ! -------------------------------------
            if (best_cost_before_rewire > goal_node_->cost_from_start)
            {
                vector<Eigen::Vector3d> curr_best_path;
                fillPath(goal_node_, curr_best_path);
                path_list_.emplace_back(curr_best_path);
                solution_cost_time_pair_list_.emplace_back(goal_node_->cost_from_start, (ros::Time::now() - rrt_start_time).toSec());
            }
        }
        /* end of rewire */
```

最后附上运行结果图：

**RRT算法：**

![1733165489743](images/README/1733165489743.png)

**RRT*算法：**

![1733164748416](images/README/1733164748416.png)

![1733165495516](images/README/1733165495516.png)
