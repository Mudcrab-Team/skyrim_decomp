// Source exposure: binary-analysis (names are guesses; layout read from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShader, BSImagespaceShader::Function1541d50, ShaderPass, ShaderPass::Reset, pass0, pass1: GUESS(low)
#pragma once

// Stand-in for the two owned objects; only the one virtual slot used is declared.
class ShaderPass
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void Reset(int arg);
};

class BSImagespaceShader
{
public:
    void Function1541d50();

    ShaderPass* pass0;  // 0x00
    ShaderPass* pass1;  // 0x08
};
