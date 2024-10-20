cmake_minimum_required(VERSION 2.8)
project(qua_lie_update)

# 查找 Eigen3 库
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# 设置 Sophus 库的头文件路径
set(Sophus_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Sophus)
include_directories(${Sophus_INCLUDE_DIR})

# 设置 Sophus 库的库文件路径
set(Sophus_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/Sophus/build)
link_directories(${Sophus_LIBRARY_DIR})

# 添加可执行文件
add_executable(qua_lie_update validation.cpp)

# 链接 Sophus 库
target_link_libraries(qua_lie_update Sophus)

MESSAGE(STATUS "Sophus_INCLUDE_DIRS: ${Sophus_INCLUDE_DIRS}")
MESSAGE(STATUS "Sophus_LIBRARY_DIR: ${Sophus_LIBRARY_DIR}")

