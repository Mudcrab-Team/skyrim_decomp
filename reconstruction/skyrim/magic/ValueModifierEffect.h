// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: original declarations with labelled community and sibling names.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6
// ValueModifierEffect, ValueModifierEffect::SetActorValue: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, unknown60, unknown80: GUESS(low)
// ValueModifierEffect::actorValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
class TESBoundObject;

class ValueModifierEffect {
public:
    void SetActorValue(std::uint32_t value);
    void Function5bcba0(const void* a_location);
    void Function5bb320(TESBoundObject* a_source, bool a_enchanting);
    void Function5bb990(bool a_enabled);
private:
    std::uint8_t unknown00[0x58];
    TESBoundObject* source;
    std::uint8_t unknown60[0x1C];
    std::uint32_t flags;
    std::uint8_t unknown80[0x10];
    std::uint32_t actorValue;
};
