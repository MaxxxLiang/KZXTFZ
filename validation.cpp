#include <iostream>
#include<Eigen/Core>
#include<Eigen/Geometry>
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
    
    //旋转矩阵更新
    
    
    //四元数更新    
    

    return 0;
}

