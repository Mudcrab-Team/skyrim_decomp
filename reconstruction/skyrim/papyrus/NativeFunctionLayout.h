// Code origin: declarations adapted from the pinned community headers identified below.
// Source exposure: mixed (pinned community declarations and local target analysis).
// NativeFunctionLayout, NativeFunctionBaseLayout, ScriptFunctionLayout, ScriptRefCountLayout,
// ScriptStringLayout, ScriptTypeLayout, ScriptDescriptorLayout: GUESS(low) STANDIN
// Field layouts: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NativeFunction and NativeLatentFunction owner spellings: EXE_RTTI
// callback, Callback: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
struct ScriptRefCountLayout {
    volatile std::uint32_t referenceCount;
};
struct ScriptStringLayout {
    const char* entry;
};
struct ScriptTypeLayout {
    std::uintptr_t value;
};
struct ScriptDescriptorLayout {
    void* entries;
    std::uint16_t parameterCount;
    std::uint16_t totalEntries;
};
class ScriptFunctionLayout : public ScriptRefCountLayout {
public:
    virtual ~ScriptFunctionLayout();
};
class NativeFunctionBaseLayout : public ScriptFunctionLayout {
public:
    ~NativeFunctionBaseLayout() override;
    ScriptStringLayout name;
    ScriptStringLayout objectName;
    ScriptStringLayout stateName;
    ScriptTypeLayout returnType;
    ScriptDescriptorLayout descriptors;
    bool isStatic;
    bool callableFromTasklet;
    bool isLatent;
    std::uint32_t userFlags;
    ScriptStringLayout docString;
};
class NativeFunctionLayout : public NativeFunctionBaseLayout {
public:
    ~NativeFunctionLayout() override;
    using Callback = void (*)();
    Callback callback;
};
static_assert(sizeof(ScriptRefCountLayout) == 4, "reference count layout");
static_assert(sizeof(ScriptFunctionLayout) == 0x10, "script function base");
static_assert(sizeof(ScriptDescriptorLayout) == 0x10, "descriptor table");
static_assert(sizeof(NativeFunctionBaseLayout) == 0x50, "native function base");
static_assert(sizeof(NativeFunctionLayout) == 0x58, "native callback specialization");
static_assert(offsetof(NativeFunctionBaseLayout, name) == 0x10, "name offset");
static_assert(offsetof(NativeFunctionBaseLayout, descriptors) == 0x30, "descriptors offset");
static_assert(offsetof(NativeFunctionBaseLayout, userFlags) == 0x44, "user flags offset");
static_assert(offsetof(NativeFunctionBaseLayout, docString) == 0x48, "documentation offset");
static_assert(offsetof(NativeFunctionLayout, callback) == 0x50, "callback offset");
}
