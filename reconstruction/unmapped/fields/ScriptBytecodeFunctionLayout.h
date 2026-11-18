// Source exposure: mixed (pinned community declarations and local target access/RTTI analysis).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; include/RE/S/ScriptFunction.h; include/RE/P/PackedInstructionStream.h; include/RE/I/IFunction.h; include/RE/V/VDescTable.h; MIT.
// Code origin: adapted data declarations only; no external implementation bodies.
// ScriptBytecodeFunctionLayout, ScriptInstructionLayout: GUESS(medium) STANDIN; represented declaration aliases, not original type identities.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: represented declaration from reconstruction/bsengine/ScriptBytecodeFunctionLayout.h; only include spelling changed.
#pragma once
#include <cstddef>
#include <cstdint>
#include "NativeFunctionLayout.h"
namespace ResearchLayouts {
// numInstructionBits, jumpTargetBitCount, localVariableBitCount, memberVariableBitCount,
// instructions, name, objName, stateName, retType, descTable, userFlags, functionType,
// isStatic, docString, sourceFileName, lineNumberCount, lineNumbers: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct ScriptInstructionLayout {
    std::uint32_t numInstructionBits;
    std::uint16_t jumpTargetBitCount;
    std::int8_t localVariableBitCount;
    std::int8_t memberVariableBitCount;
    void* instructions;
};
class ScriptBytecodeFunctionLayout : public ScriptFunctionLayout {
public:
    ~ScriptBytecodeFunctionLayout() override;
    ScriptStringLayout name;
    ScriptStringLayout objName;
    ScriptStringLayout stateName;
    ScriptTypeLayout retType;
    ScriptDescriptorLayout descTable;
    std::uint32_t userFlags;
    ScriptInstructionLayout instructions;
    std::uint16_t functionType;
    bool isStatic;
    ScriptStringLayout docString;
    ScriptStringLayout sourceFileName;
    std::uint32_t lineNumberCount;
    std::uint16_t* lineNumbers;
};
static_assert(sizeof(ScriptInstructionLayout) == 16, "public instruction stream fields");
static_assert(sizeof(ScriptBytecodeFunctionLayout) == 128, "public size and target sized delete");
static_assert(offsetof(ScriptBytecodeFunctionLayout, name) == 16, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, objName) == 24, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, stateName) == 32, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, retType) == 40, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, descTable) == 48, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, userFlags) == 64, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, instructions) == 72, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, functionType) == 88, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, isStatic) == 90, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, docString) == 96, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, sourceFileName) == 104, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, lineNumberCount) == 112, "public field offset");
static_assert(offsetof(ScriptBytecodeFunctionLayout, lineNumbers) == 120, "public field offset");
}
