# 倘若将来使用arm平台，只需要在这里配置交叉编译器即可

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_C_FLAGS "-std=gnu99 -Wno-format-security")
set(CMAKE_CXX_FLAGS "-Wno-format-security")
set(CMAKE_C_FLAGS_DEBUG "-Wall -g -rdynamic")
set(CMAKE_C_FLAGS_RELEASE "-Wall -O3 -s")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -rdynamic")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O3 -s")