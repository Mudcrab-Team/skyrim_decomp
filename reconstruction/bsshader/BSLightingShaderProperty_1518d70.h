// Source exposure: mixed
// Code origin: original reconstruction from authorized local binary analysis; community class name only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RunWithTaskFlag, RunBaseTask: GUESS(low); method purpose and signature remain unknown.
// TaskFlagScope, saved, threadTaskFlag: GUESS(low); scoped task-state restoration.
#pragma once

extern __declspec(thread) unsigned int threadTaskFlag;

class TaskFlagScope
{
public:
    unsigned int saved;
    TaskFlagScope() : saved(threadTaskFlag) { threadTaskFlag = 30; }
    ~TaskFlagScope() { threadTaskFlag = saved; }
};

class BSLightingShaderProperty
{
public:
    void RunWithTaskFlag(void* context);
    void RunBaseTask(void* context);
};
