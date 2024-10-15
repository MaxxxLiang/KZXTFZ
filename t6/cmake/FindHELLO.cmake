FIND_PATH(HELLO_INCLUDE_DIR hello.h /usr/include/hello /usr/local/include/hello)
FIND_LIBRARY(HELLO_LIBRARY NAMES hello PATH /usr/lib /usr/local/lib)
IF(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
#定义变量并设置属性
   SET(HELLO_FOUND TRUE)
ENDIF(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
IF(HELLO_FOUND)
# QUIET参数，对应与我们编写的FindHELLO中的 HELLO_FIND_QUIETLY
#如果不指定 这个参数，就会执行： "MESSAGE(STATUS "Found Hello: ${HELLO_LIBRARY}")"
   IF(NOT HELLO_FIND_QUIETLY)
       MESSAGE(STATUS "Found Hello: ${HELLO_LIBRARY}")
   ENDIF(NOT HELLO_FIND_QUIETLY)
ELSE(HELLO_FOUND)
#REQUIRED 参数，其含义是指这个共享库是否是工程必须的，如果使用了这个参数，说明这个链接库是必备库
#如果找不到这个链接库，则工程不能编译
   IF(HELLO_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find hello library")
   ENDIF(HELLO_FIND_REQUIRED)
ENDIF(HELLO_FOUND)
