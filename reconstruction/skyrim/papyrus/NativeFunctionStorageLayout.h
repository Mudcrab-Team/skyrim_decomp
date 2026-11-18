// Source exposure: mixed (pinned community declarations and local target analysis).
// NativeFunctionLayout, NativeFunctionBaseLayout, ScriptFunctionLayout, ScriptRefCountLayout,
// ScriptStringLayout, ScriptTypeLayout, ScriptDescriptorLayout: GUESS(low) STANDIN
// Field layouts: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NativeFunction and NativeLatentFunction owner spellings: EXE_RTTI
// callback, Callback: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted from published p106 represented declaration reconstruction/bsengine/NativeFunctionLayout.h.
// ScriptRefCountStorageLayout, ScriptStringStorageLayout, ScriptTypeStorageLayout, ScriptDescriptorStorageLayout, ScriptFunctionStorageLayout, NativeFunctionBaseStorageLayout, NativeFunctionStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
struct ScriptRefCountStorageLayout {
    volatile std::uint32_t referenceCount;
};
struct ScriptStringStorageLayout {
    const char* entry;
};
struct ScriptTypeStorageLayout {
    std::uintptr_t value;
};
struct ScriptDescriptorStorageLayout {
    void* entries;
    std::uint16_t parameterCount;
    std::uint16_t totalEntries;
};
class ScriptFunctionStorageLayout : public ScriptRefCountStorageLayout {
public:
    virtual ~ScriptFunctionStorageLayout();
};
class NativeFunctionBaseStorageLayout : public ScriptFunctionStorageLayout {
public:
    ~NativeFunctionBaseStorageLayout() override;
    ScriptStringStorageLayout name;
    ScriptStringStorageLayout objectName;
    ScriptStringStorageLayout stateName;
    ScriptTypeStorageLayout returnType;
    ScriptDescriptorStorageLayout descriptors;
    bool isStatic;
    bool callableFromTasklet;
    bool isLatent;
    std::uint32_t userFlags;
    ScriptStringStorageLayout docString;
};
class NativeFunctionStorageLayout : public NativeFunctionBaseStorageLayout {
public:
    ~NativeFunctionStorageLayout() override;
    using Callback = void (*)();
    Callback callback;
};
static_assert(sizeof(ScriptRefCountStorageLayout) == 4, "reference count layout");
static_assert(sizeof(ScriptFunctionStorageLayout) == 0x10, "script function base");
static_assert(sizeof(ScriptDescriptorStorageLayout) == 0x10, "descriptor table");
static_assert(sizeof(NativeFunctionBaseStorageLayout) == 0x50, "native function base");
static_assert(sizeof(NativeFunctionStorageLayout) == 0x58, "native callback specialization");
static_assert(offsetof(NativeFunctionBaseStorageLayout, name) == 0x10, "name offset");
static_assert(offsetof(NativeFunctionBaseStorageLayout, descriptors) == 0x30, "descriptors offset");
static_assert(offsetof(NativeFunctionBaseStorageLayout, userFlags) == 0x44, "user flags offset");
static_assert(offsetof(NativeFunctionBaseStorageLayout, docString) == 0x48, "documentation offset");
static_assert(offsetof(NativeFunctionStorageLayout, callback) == 0x50, "callback offset");
}
