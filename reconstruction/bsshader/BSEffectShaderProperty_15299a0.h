// Code origin: original minimal declarations using the cited community class name and local accesses.
// Source exposure: mixed (pinned image and community class name).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSEffectShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// WithMemoryContext, ForwardEffectOperation, effectMemoryContext, previous: GUESS(low); operation identity is unresolved.
// AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24); helper name only, body original.
// 0x15299a0 BSEffectShaderProperty::WithMemoryContext
#pragma once
#include <cstdint>

extern __declspec(thread) std::uint32_t effectMemoryContext;
class BSEffectShaderProperty
{
public:
    void WithMemoryContext(void* argument);
    void ForwardEffectOperation(void* argument);
};
