
# cmake minimum required version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(tool_proj)
# add all source files and head files in current directory into SRC_LIST
AUX_SOURCE_DIRECTORY(. SRC_LIST)
# produce app
ADD_EXECUTABLE(tool_main ${SRC_LIST})







