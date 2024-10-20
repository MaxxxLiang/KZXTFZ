#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

int main(int argc, char** argv) {
    //
    Eigen::Vector3d pInC (0.3,0.2,1.2);
    Eigen::Vector3d pInB;
    Eigen::Vector3d pInL;
    Eigen::Vector3d pInR;
    Eigen::Vector3d pInW;

    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();

    Eigen::Quaterniond q_wr (0.55, 0.3, 0.2, 0.2); 
    Eigen::Vector3d t_wr (0.1, 0.2, 0.3);

    Eigen::Quaterniond q_rb (0.99, 0, 0, 0.01);
    Eigen::Vector3d t_rb (0.05, 0, 0.5);

    Eigen::Quaterniond q_bl (0.3, 0.5, 0, 20.1);
    Eigen::Vector3d t_bl (0.4, 0, 0.5);

    Eigen::Quaterniond q_bc (0.8, 0.2, 0.1, 0.1);
    Eigen::Vector3d t_bc (0.5, 0.1, 0.5);

    //
    Eigen::Matrix3d r_bc = q_bc.normalized().toRotationMatrix();
    Eigen::Matrix3d r_bl = q_bl.normalized().toRotationMatrix();
    Eigen::Matrix3d r_rb = q_rb.normalized().toRotationMatrix();
    Eigen::Matrix3d r_wr = q_wr.normalized().toRotationMatrix();

    //
    Eigen::Matrix3d r_cb = r_bc.inverse();
    Eigen::Matrix3d r_br = r_rb.inverse();
    Eigen::Matrix3d r_rw = r_wr.inverse();

    //c->b 
    pInB = r_cb * (pInC - t_bc);

    //b->l 
    pInL = (r_bl * pInB) + t_bl;

    //b->r 
    pInR = r_br * (pInB - t_rb);

    //r->w 
    pInW = r_rw * (pInR - t_wr);

    std::cout<<"c to l rotation: Point in Laser"<<pInL.transpose()<<std::endl;
    std::cout<<"c to w rotation: Point in World"<<pInW.transpose()<<std::endl;

    return 0;
}