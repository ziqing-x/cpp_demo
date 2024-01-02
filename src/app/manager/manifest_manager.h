/*
 * @Author: xiongyi jassimxiong@gmail.com
 * @Date: 2023-12-27 17:23:59
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-27 17:26:08
 * @FilePath: /uav_embedd/src/app/manager/manifest_manager.h
 * @Description:
 *
 * Copyright (c) 2023 广东人工智能与先进计算研究院, 版权所有
 */
#ifndef __MANIFEST_MANAGER_H__
#define __MANIFEST_MANAGER_H__

#include "manifest.h"

class ManifestManager
{
private:
    Manifest manifest_;

public:
    ManifestManager();
    ~ManifestManager();
    auto get_manifest() const -> const Manifest &;
};

#endif // __MANIFEST_MANAGER_H__