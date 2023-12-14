# APP_NAME: 对外的名称，可以和进程名一致
# PKG_NAME: 包名, 用公司域名倒过来 + app_name保证唯一性
# VERSION： 版本名，X.Y.Z
# 1、X为主版本，不需要向下兼；
# 2、Y为次版本，向下兼容，属于增量升级, 例如增加新功能，新接口；
# 3、Z为修订版本, 向下兼容, 比如修复某个函数里的某个逻辑;
# DESCRIPTION： 升级包描述
# APP_ROOT_DIR: 安装到目标设备的什么路径
# BUILD_DATE: 编译代码时的时间
# ARCH: 处理器架构
# PLATFORM： 系统平台

set(VERSION "1.0.0")
set(DESCRIPTION "It's demo")
set(APP_NAME "${PROJECT_NAME}")
set(PKG_NAME "com.xxx.${APP_NAME}")
set(SERVICE "${APP_NAME}.service")
set(ARCH "x64")
set(PLATFORM "linux")
set(APP_ROOT_DIR "/opt/${PKG_NAME}")
string(TIMESTAMP BUILD_DATE "%Y-%m-%d %H:%M:%S")
