// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original polymorphic reconstruction with provisional method signatures.
// SPDX-License-Identifier: CC0-1.0
// ActionInput: STANDIN EXE_RTTI
// ActionInput::~ActionInput, ActionInput::Unk_01, ActionInput::Unk_02, ActionInput::Unk_03, ActionInput::ActionInput, ActionInput::first, ActionInput::second, ActionInput::context, ActionInput::tag: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
#include <Windows.h>

// ActionRef1f3a20: STANDIN GUESS(low)
struct ActionRefBase1f3a20 { virtual ~ActionRefBase1f3a20(); virtual void DeleteThis(); volatile long references; };
struct ActionRef1f3a20 { std::uint8_t unknown00[32]; ActionRefBase1f3a20 base; };
// ActionOwner1f3a20: STANDIN GUESS(low)
struct ActionOwner1f3a20 {
    ActionRef1f3a20* value;
    explicit ActionOwner1f3a20(ActionRef1f3a20* incoming) : value(incoming) {
        if (value) {
            // Atomic acquisition shares the reference with other owners.
            _InterlockedIncrement(&value->base.references);
        }
    }
    ~ActionOwner1f3a20() {
        if (value) {
            // Atomic release detects the final intrusive owner.
            if ((_InterlockedDecrement(&value->base.references) & 0x3ff) == 0) value->base.DeleteThis();
        }
    }
};

class ActionInput
{
public:
    virtual ~ActionInput();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    ActionInput(std::uint32_t inputTag, ActionRef1f3a20* inputFirst, void* inputContext, ActionRef1f3a20* inputSecond);
    ActionOwner1f3a20 first;
    ActionOwner1f3a20 second;
    void* context;
    std::uint32_t tag;
    std::uint8_t unknown24[4];
};
static_assert(offsetof(ActionInput, first) == 8, "member position");
static_assert(offsetof(ActionInput, second) == 16, "member position");
static_assert(offsetof(ActionInput, context) == 24, "member position");
static_assert(offsetof(ActionInput, tag) == 32, "member position");
static_assert(sizeof(ActionInput) == 40, "observed class size");
