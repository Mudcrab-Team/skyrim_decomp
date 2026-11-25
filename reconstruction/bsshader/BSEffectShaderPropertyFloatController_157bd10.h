// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSEffectShaderPropertyFloatController, NiTimeController, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LinkObject: SYMBOLS(tesv-2013-map)
// NiTimeController::LinkObject: CRASHLOGGER_PDB(59818@2026.10.24)
// activeMemoryTag, MemoryTagScope, saved: GUESS(low); scoped allocation category
#pragma once
#include <cstdint>

class NiStream;
extern __declspec(thread) std::uint32_t activeMemoryTag;
class NiTimeController {
public:
    void LinkObject(NiStream& stream);
};
class BSEffectShaderPropertyFloatController : public NiTimeController {
public:
    void LinkObject(NiStream& stream);
};
class MemoryTagScope {
public:
    explicit MemoryTagScope(std::uint32_t tag) : saved(activeMemoryTag) { activeMemoryTag = tag; }
    ~MemoryTagScope() { activeMemoryTag = saved; }
private:
    std::uint32_t saved;
};
