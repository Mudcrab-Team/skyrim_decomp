// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// The compared method is the CrashLogger sub_141330CC0 entry, declared here as Function158ad50.
// BSImagespaceShaderISBlur, BSImagespaceShaderISBlur::sub_141330CC0: CRASHLOGGER_PDB(59818@2026.10.24)
// Function158ad50, Function1579120, Function10104f0, Renderer3331f30, ConstantPool3331f40, g_renderer, g_constantPool, VFunc00..VFunc16, unk00, unk1A1: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Renderer3331f30
{
public:
    virtual void VFunc00();
    virtual void VFunc01();
    virtual void VFunc02();
    virtual void VFunc03();
    virtual void VFunc04();
    virtual void VFunc05();
    virtual void VFunc06();
    virtual void VFunc07(std::int32_t a_arg1, std::int32_t a_arg2, void* a_ptr);  // +0x38
    virtual void VFunc08();
    virtual void VFunc09();
    virtual void VFunc10();
    virtual void VFunc11();
    virtual void VFunc12();
    virtual void VFunc13();
    virtual void VFunc14();
    virtual void VFunc15(void* a_data, std::int32_t a_flag);  // +0x78
    virtual void VFunc16(std::int32_t a_arg1, std::int32_t a_arg2, void* a_ptr);  // +0x80
};

struct ConstantPool3331f40
{
    void** Function10104f0(std::int32_t a_size, void** a_outBuf, std::int32_t a_count);  // callee at 0x10104f0, not compared
};

extern Renderer3331f30* g_renderer;
extern ConstantPool3331f40 g_constantPool;

class BSImagespaceShaderISBlur
{
public:
    void Function1579120(std::int32_t a_a, std::int32_t a_b, std::int32_t a_c);  // callee at 0x1579120, not compared
    void Function158ad50(const void* a_src);                                       // compared: 0x158ad50

    std::uint8_t unk00[0x1A1];  // 00
    std::uint8_t unk1A1;        // 1A1
};
static_assert(offsetof(BSImagespaceShaderISBlur, unk1A1) == 0x1A1, "unk1A1 offset");
