<!--
 * @Author: xiongyi jassimxiong@gmail.com
 * @Date: 2023-12-14 11:06:16
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 16:01:48
 * @FilePath: /cpp_demo/readme.md
 * @Description: 
 * 
 * Copyright (c) 2023 xxx, 版权所有
-->
<p align="center">
  <h3 align="center">CPP DEMO</h3>
  <p align="center">
    这是一个使用cmake构建cpp代码的demo
  <br>
</p>

<p align="center">
    <a href="#Language" alt="Language"><img src="https://img.shields.io/badge/language-cmake%20%7C%20shell%20%7C%20c%2Fc%2B%2B-blue" /></a>
    <a href="#arch" alt="arch"><img src="https://img.shields.io/badge/arch-x86%20-important" /></a>
    <a href="#platform" alt="platform"><img src="https://img.shields.io/badge/platform-linux-blueviolet" /></a>
</p>

***
- 索引
  - [代码](#代码)
  - [构建](#构建)
  - [安装](#安装)
  - [卸载](#卸载)
  - [启动](#启动)

### 代码
```bash
.
├── cmake                   # cmake模块化代码:
├── config                  # 配置文件:
│   ├── app.conf.in         # 应用配置文件
│   └── app.service.in      # 服务配置文件
└── src                     # 源码:
    ├── 3party              # 第三方库:
    │   ├── doctest         # 单元测试库
    │   ├── json            # json库
    │   └── spdlog          # 日志库
    ├── app                 # 嵌入式这边负责的模块:
    │   ├── common          # 通用
    │   ├── manager         # 管理器
    │   ├── network         # 网络相关
    │   └── updater         # 软件包更新
    └── test                # 单元测试:
```

### 构建

```bash
make help  # 帮助
make build # 编译
make pack  # 打包
make clean # 清除
make check # 静态检查代码，需要安装cppcheck， sudo apt install cppcheck
```
### 安装

```bash
sudo dpkg -i build/cn.xxx.demo_1.0.0_amd64.deb
```

### 卸载

```bash
sudo dpkg -r com.xxx.demo
```

### 启动

```bash
每次安装完.deb包后运行如下命令
sudo systemctl daemon-reload
sudo systemctl enable nest.service # 自启动
sudo systemctl disable nest.service # 禁止自启动
```

***
👩‍💻 <font color = green>问题反馈:</font> jassimxiong@gmail.com


<p align="center">Copyright (C), 2018-2023, xxx，版权所有.<p>
