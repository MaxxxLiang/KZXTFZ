#语法 PROJECT(projectname [CXX] [C] [Java]) 可以指定工程支持的语言
PROJECT(HELLO)
#语法 SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])
SET(SRC_LIST main.c)
#语法 MESSAGE([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...) 
MESSAGE(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${HELLO_SOURCE_DIR})
#生成可执行文件 可以直接写成 ADD_EXECUTABLE(hello main.c) 
ADD_EXECUTABLE(hello ${SRC_LIST})