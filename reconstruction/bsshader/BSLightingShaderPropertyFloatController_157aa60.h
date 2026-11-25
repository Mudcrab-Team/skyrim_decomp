// Source exposure: mixed (local binary analysis and community name declarations).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderPropertyFloatController, NiFloatInterpController, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LinkObject: SYMBOLS(fo4-pdb); candidate name mapped from the stream-operation position
// allocationTag, AllocationTagScope, saved: GUESS(low); scoped allocator category inferred from TLS lifetime
#pragma once
#include <cstdint>

class NiStream;
class NiFloatInterpController
{
public:
    void LinkObject(NiStream& stream);
};

class BSLightingShaderPropertyFloatController : public NiFloatInterpController
{
public:
    void LinkObject(NiStream& stream);
};

extern __declspec(thread) std::uint32_t allocationTag;
class AllocationTagScope
{
public:
    explicit AllocationTagScope(std::uint32_t tag) : saved(allocationTag) { allocationTag = tag; }
    ~AllocationTagScope() { allocationTag = saved; }
private:
    std::uint32_t saved;
};
