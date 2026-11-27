// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShaderLensFlare, BSImagespaceShader: CRASHLOGGER_PDB(59818@2026.10.24); names only
// BSImagespaceShader: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only the size 0x1A8 and an out-of-line destructor, which the target calls
// The destructor is implicit on purpose: a declared empty destructor adds a store of the derived vtable pointer that the target lacks.
// ParamSet, ParamSet::~ParamSet, TexEntry, TexEntry::~TexEntry, param, entryA, entryB, entryC: STANDIN GUESS(low); a 0x80-byte member at 0x1A8 (destructor callee at 0x152aeb0) and three 0x20-byte members at 0x228, 0x248 and 0x268 (destructor callee at 0x1554ed0)
#pragma once

#include <cstdint>
#include <cstddef>

class BSImagespaceShader
{
public:
    BSImagespaceShader();
    virtual ~BSImagespaceShader();  // callee at 0x15647f0 in its plain form, not compared here
    std::uint8_t unk08[0x1a0];
};
static_assert(sizeof(BSImagespaceShader) == 0x1a8, "BSImagespaceShader size");

class ParamSet
{
public:
    ParamSet();
    ~ParamSet();  // callee at 0x152aeb0, not compared here
    std::uint8_t unk00[0x80];
};

class TexEntry
{
public:
    TexEntry();
    ~TexEntry();  // callee at 0x1554ed0, not compared here
    std::uint8_t unk00[0x20];
};

class BSImagespaceShaderLensFlare : public BSImagespaceShader
{
public:
    BSImagespaceShaderLensFlare();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x15307b0

    ParamSet param;   // 1A8
    TexEntry entryA;  // 228
    TexEntry entryB;  // 248
    TexEntry entryC;  // 268
    std::uint8_t unk288[0x10];
};
static_assert(sizeof(BSImagespaceShaderLensFlare) == 0x298, "BSImagespaceShaderLensFlare size");
