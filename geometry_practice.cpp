#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

int main(int argc, char** argv) {
    Eigen::Quaterniond q_wr (0.55, 0.3, 0.2, 0.2); 
    Eigen::Vector3d t_wr (0.1, 0.2, 0.3);

    Eigen::Quaterniond q_rb (0.99, 0, 0, 0.01);
    Eigen::Vector3d t_rb (0.05, 0, 0.5);

    Eigen::Quaterniond q_bl (0.3, 0.5, 0, 20.1);
    Eigen::Vector3d t_bl (0.4, 0, 0.5);

    Eigen::Quaterniond q_bc (0.8, 0.2, 0.1, 0.1);
    Eigen::Vector3d t_bc (0.5, 0.1, 0.5);

    

    return 0;
}