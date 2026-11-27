// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x15652a0 BSImagespaceShader::ShutDown
#include "BSImagespaceShader_15652a0.h"

BSImagespaceShader::~BSImagespaceShader()
{
}

void BSImagespaceShader::ShutDown()
{
    Function1579050();
    if (hasResource)
    {
        Function1589eb0(resource);
        delete resource;
        resource = nullptr;
    }
}
