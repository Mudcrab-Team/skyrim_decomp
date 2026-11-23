// Source exposure: mixed (local access, copy, RTTI and size evidence).
// CodeTaskletFieldLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// BSScript::Internal::CodeTasklet: EXE_RTTI
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT; include/RE/C/CodeTasklet.h and include/RE/I/IFuncCallQuery.h.
// Code origin: adapted public data declarations only, no external implementation body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "../unmapped/leaves/CommunityLeafStorageLayout.h"
namespace ResearchLayouts {
// stack, vm, errorLogger, resumeReason, topFrame, frameMemoryPage, jumpBitCount, localVarBitCount, memberVarBitCount, instructionDataBitCount, instructionDataStart: GUESS(medium) STANDIN; physical fields, meanings unverified.
class CodeTaskletFieldLayout : public CommunityRef14c8960 { public: ~CodeTaskletFieldLayout();
    void* stack;
    void* vm;
    void* errorLogger;
    std::uint32_t resumeReason;
    void* topFrame;
    std::uint32_t frameMemoryPage;
    std::int8_t jumpBitCount;
    std::int8_t localVarBitCount;
    std::int8_t memberVarBitCount;
    std::uint32_t instructionDataBitCount;
    const void* instructionDataStart;
};
static_assert(sizeof(CodeTaskletFieldLayout)==80,"represented size");
static_assert(offsetof(CodeTaskletFieldLayout,stack)==16,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,vm)==24,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,errorLogger)==32,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,resumeReason)==40,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,topFrame)==48,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,frameMemoryPage)==56,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,jumpBitCount)==60,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,localVarBitCount)==61,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,memberVarBitCount)==62,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,instructionDataBitCount)==64,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,instructionDataStart)==72,"observed field offset");
}
