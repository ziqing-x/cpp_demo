# 生成固件包原始文件
include(GNUInstallDirs)

set(TARGET ${PROJECT_BINARY_DIR})

configure_file(${TOP}/infile/app.conf.in ${TARGET}/config/app.conf @ONLY)
configure_file(${TOP}/infile/manifest.info.in ${TARGET}/manifest.info @ONLY)
configure_file(${TOP}/infile/app.service.in ${TARGET}/${SERVICE} @ONLY)
