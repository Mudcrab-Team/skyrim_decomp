// CI hash: 0x1f3a20 ??0ActionInput@@QEAA@IPEAUActionRef1f3a20@@PEAX0@Z
// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original polymorphic reconstruction with provisional method signatures.
// SPDX-License-Identifier: CC0-1.0
// ActionInput: STANDIN EXE_RTTI
// ActionInput::~ActionInput, ActionInput::Unk_01, ActionInput::Unk_02, ActionInput::Unk_03, ActionInput::ActionInput, ActionInput::first, ActionInput::second, ActionInput::context, ActionInput::tag: GUESS(low)
// 0x1f3a20 ActionInput::ActionInput
#include "ActionInput_1f3a20.h"

// Initialize the object state.
ActionInput::ActionInput(std::uint32_t inputTag, ActionRef1f3a20* inputFirst, void* inputContext, ActionRef1f3a20* inputSecond) : first(inputFirst), second(inputSecond), context(inputContext), tag(inputTag)
{
}
