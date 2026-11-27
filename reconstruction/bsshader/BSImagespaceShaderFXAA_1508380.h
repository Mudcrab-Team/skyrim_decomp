// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShaderFXAA, BSImagespaceShader: CRASHLOGGER_PDB(59818@2026.10.24); names only
// BSImagespaceShader: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only the size 0x1A8 and an out-of-line destructor, which the target calls
// The destructor is implicit on purpose: a declared empty destructor adds a store of the derived vtable pointer that the target lacks.
// ParamSet, ParamSet::~ParamSet, param: STANDIN GUESS(low); the member at 0x1A8 with an out-of-line destructor (callee at 0x152aeb0)
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

class BSImagespaceShaderFXAA : public BSImagespaceShader
{
public:
    BSImagespaceShaderFXAA();

    ParamSet param;  // 1A8
};
static_assert(sizeof(BSImagespaceShaderFXAA) == 0x228, "BSImagespaceShaderFXAA size");
