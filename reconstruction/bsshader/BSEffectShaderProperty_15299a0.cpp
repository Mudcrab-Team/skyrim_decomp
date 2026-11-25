// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header.
// Source exposure: mixed (pinned image and community class name).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 21
// 0x15299a0 BSEffectShaderProperty::WithMemoryContext
#include "BSEffectShaderProperty_15299a0.h"

// AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24); minimal scope-guard stand-in.
class AutoMemContext
{
public:
    AutoMemContext() : previous(effectMemoryContext) { effectMemoryContext = 30; }
    ~AutoMemContext() { effectMemoryContext = previous; }
private:
    std::uint32_t previous;
};

void BSEffectShaderProperty::WithMemoryContext(void* argument)
{
    AutoMemContext context;
    ForwardEffectOperation(argument);
}
