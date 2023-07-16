### CMakeLists.txt

~~~cmake
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(LeetCode VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)  # 设置这一项可以替代set(CMAKE_CXX_FLAGS "-std=c++20")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g") # 使cmake输出调试信息

set(CMAKE_BUILD_TYPE "Debug")  # 设置编译类型

# add_library()     # 构建库
add_executable(LeetCode P1004.cpp)  # 构建可执行文件

if (CMAKE_SIZEOF_VOID_P EQUAL 8) # 用于根据系统环境生成64/32位程序
    message(STATUS "64 bits compiler detected")
    set(EX_PLATFORM 64)
    set(EX_PLATFORM_NAME "x64")
else (CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "32 bits compiler detected")
    set(EX_PLATFORM 32)
    set(EX_PLATFORM_NAME "x86")
endif (CMAKE_SIZEOF_VOID_P EQUAL 8)

if (EX_PLATFORM EQUAL 64)
    message("Outputting to lib64 and bin64")
    # ----- setup output directories -----
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib64
    CACHE PATH "Single directory for all libraries")
    # ----- setup the Executable output directories -----
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin64
    CACHE PATH "Single directory for all Executables.")
    # ----- setup the Executable output directories -----
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib64
    CACHE PATH "Single directory for all static libraries.")
else (EX_PLATFORM EQUAL 64)
    message("Outputting to lib and bin")
    # ----- setup output directories -----
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    CACHE PATH "Single directory for all libraries")
    # ----- setup the Executable output directories -----
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    CACHE PATH "Single directory for all Executables.")
    # ----- setup the Executable output directories -----
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    CACHE PATH "Single directory for all static libraries.")
endif (EX_PLATFORM EQUAL 64)

# add_library()  # 添加库

# add_subdirectory()  # 添加子目录
# target_link_libraries()  # 链接库
# 如果目标文件有要包含的头文件目录，则将头文件的目录添加到目标文件
# target_include_directories(<target> <PRIVATE|PUBLIC|INTERFACE> <header_dir>)

# 设置编译选项
# target_compile_options(<target> <PRIVATE|PUBLIC|INTERFACE> <option>)
# target_compile_definitions(<target> <PRIVATE|PUBLIC|INTERFACE> <definition>)
# target_compile_features(<target> <PRIVATE|PUBLIC|INTERFACE> <feature>)

# 设置源文件
# target_sources(<target> <PRIVATE|PUBLIC|INTERFACE> <src_dir>)

# 设置链接库
# target_link_libraries(<target> <PRIVATE|PUBLIC|INTERFACE> <lib_name>)

# 设置依赖库, 安装代码
# install()
~~~

### LLDB调试命令

~~~sh
lldb <filename> # 对filename进行调试

break set -l <line> -f <filename> # 设置断点为filename文件的第line行
	# break选项
		-n <funcname> # 指定断点为funcname函数
		-c <expr> # 设置断点条件<expr>，如i==1
breakpoint list # 查看断点列表
breakpoint delete 1 #  删除第一组断点
breakpoint delete # 删除所有断点

run(r) # 启动目标程序
continue(c) # 继续运行程序直到遇到断点
next(n) # 单步运行,不会进入子函数
step(s) # 单步运行,遇到子函数会进去
finish # 跳出当前函数

frame variable # 列出当前所有的变量值
print(p) <变量名> # 查看变量值
expr <expr> # 设置变量值，如a = 0
~~~

### VSCode的launch.json

~~~json
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "type": "lldb",
            "request": "launch",
            "name": "Launch",
            "program": "${workspaceFolder}/build/bin64/${workspaceFolderBasename}", // 根据项目文件夹名来调试程序
            "args": [],
            "cwd": "${workspaceFolder}"
        }
    ]
}
~~~

