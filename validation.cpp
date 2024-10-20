#include <iostream>
#include<Eigen/Core>
#include<Eigen/Geometry>
#include "sophus/so3.h"
#include "sophus/se3.h"
using namespace std;

int main(int argc, char **argv) {
    //变量初始化
    Eigen::Vector3d w(0.01,0.02,0.03);//小量角速度（旋转向量）
    Eigen::Matrix3d R=Eigen::AngleAxisd(M_PI/4,Eigen::Vector3d(0,0,1)).toRotationMatrix();//初始旋转矩阵，绕Z轴旋转45°
    Eigen::Quaterniond q(R);//初始四元数
    cout<<"初始旋转矩阵："<<endl;
    cout<<R<<endl;
    cout<<"初始四元数："<<endl;
    cout<<q.coeffs().transpose() <<endl;

    //将w进行分解
    double theta = w.norm();//模长
    Eigen::Vector3d axis = w/theta;//转轴

    //通过李群库求指数映射
    Eigen::Matrix3d w_hat = Sophus::SO3::hat(w);//求反对称矩阵
    Eigen::Matrix3d w_exp = Sophus::SO3::exp(w).matrix();//计算指数映射 实际上exp返回的是一个四元数 需要通过matrix()把它转换成旋转矩阵

    //计算四元数乘数
    Eigen::Quaterniond q_mult(1, w(0) / 2, w(1) / 2, w(2) / 2);
    cout<<"四元数乘数 \n"<<q_mult.coeffs().transpose()<<endl;
    
    //旋转矩阵更新
    Eigen::Matrix3d R_new = R * w_exp;
    cout<<"旋转矩阵更新 \n"<<R_new<<endl;
    
    //四元数更新    
    Eigen::Quaterniond q_new;
    q_new = q * q_mult;
    cout<<"四元数更新 \n"<<q_new.coeffs().transpose()<<endl;
    cout<<"更新四元数对应旋转矩阵： \n"<<q_new.toRotationMatrix()<<endl;


    return 0;
}

