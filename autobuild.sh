#!/bin/bash

# 当脚本中任一命令失败时终止脚本执行
set -e

# 执行清理脚本
./clean_build.sh

# 创建构建目录
BUILD_DIR="./build"
mkdir -p "$BUILD_DIR"

# 进入构建目录
cd "$BUILD_DIR"

# 运行CMake配置和构建项目
cmake ..
make

# 返回到脚本所在的目录
cd ..

# 将头文件复制到库目录
INCLUDE_DIR="./src/include"
LIB_DIR="./lib"

# 创建库目录（如果不存在）
mkdir -p "$LIB_DIR"

# 复制文件
cp -r "$INCLUDE_DIR" "$LIB_DIR"

echo "Build and copy completed successfully."

