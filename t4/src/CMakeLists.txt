#从main.c生成可执行文件
ADD_EXECUTABLE(main main.c)
#添加头文件搜索路径
# INCLUDE_DIRECTORIES(/usr/include/hello)
FIND_PATH(myHeader hello.h)
IF(myHeader)
INCLUDE_DIRECTORIES(${myHeader})
ENDIF(myHeader)
#添加非标准的共享库搜索路径 hello也可以写成libhello.so
TARGET_LINK_LIBRARIES(main hello)