// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFadeNode: EXE_RTTI
// InitRuntimeData: GUESS(low)
// NiNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class NiNode
{
public:
    NiNode(std::uint32_t initialCapacity);
    virtual ~NiNode();

private:
    std::uint8_t padding08[0x120];
};

class BSFadeNode : public NiNode
{
public:
    BSFadeNode();
    ~BSFadeNode() override;

private:
    void InitRuntimeData() noexcept;
    std::uint8_t padding128[0x30];
};
static_assert(sizeof(BSFadeNode) == 0x158, "observed allocation size");
