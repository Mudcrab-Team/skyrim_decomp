// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShaderLensFlareVisibility, BSImagespaceShader: CRASHLOGGER_PDB(59818@2026.10.24); names only
// BSImagespaceShader: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only the size 0x1A8 and an out-of-line destructor, which the target calls
// The destructor is implicit on purpose: a declared empty destructor adds a store of the derived vtable pointer that the target lacks.
// TexEntry, TexEntry::~TexEntry, entryA, entryB: STANDIN GUESS(low); two members of 0x20 bytes at 0x1A8 and 0x1C8 with an out-of-line destructor (callee at 0x1554ed0)
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

class TexEntry
{
public:
    TexEntry();
    ~TexEntry();  // callee at 0x1554ed0, not compared here
    std::uint8_t unk00[0x20];
};

class BSImagespaceShaderLensFlareVisibility : public BSImagespaceShader
{
public:
    BSImagespaceShaderLensFlareVisibility();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x1530820

    TexEntry entryA;  // 1A8
    TexEntry entryB;  // 1C8
};
static_assert(sizeof(BSImagespaceShaderLensFlareVisibility) == 0x1e8, "BSImagespaceShaderLensFlareVisibility size");
