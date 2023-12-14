# 生成固件包原始文件
include(GNUInstallDirs)

set(TARGET ${PROJECT_BINARY_DIR})

configure_file(${TOP}/config/app.conf.in ${TARGET}/config/app.conf @ONLY)
configure_file(${TOP}/config/app.service.in ${TARGET}/${SERVICE} @ONLY)
