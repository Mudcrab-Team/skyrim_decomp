// Source exposure: mixed
// Code origin: original reconstruction from authorized local binary analysis; community class name only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RunWithTaskFlag, RunBaseTask: GUESS(low); scoped task call, exact identity unknown.
// TaskFlagScope, threadTaskFlag: GUESS(low); restoration guard and thread-local task state.
// 0x1518d70 BSLightingShaderProperty::RunWithTaskFlag
#include "BSLightingShaderProperty_1518d70.h"

// Run the base operation with a temporary thread task flag.
void BSLightingShaderProperty::RunWithTaskFlag(void* context)
{
    TaskFlagScope scope;
    RunBaseTask(context);
}
