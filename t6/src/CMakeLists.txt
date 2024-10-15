# 手动包含 FindHELLO.cmake 文件
# include("/home/maxliang/code/cmake/t6/cmake/FindHELLO.cmake")
#如果不定义 REQUIRED 那么库不是必须的,构建时如果找不到库 不会影响构建
FIND_PACKAGE(HELLO REQUIRED)
IF(HELLO_FOUND)
    ADD_EXECUTABLE(hello main.c)
    INCLUDE_DIRECTORIES(${HELLO_INCLUDE_DIR})
    #定义库路径
    TARGET_LINK_LIBRARIES(hello ${HELLO_LIBRARY})
ENDIF(HELLO_FOUND)