// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShader: CRASHLOGGER_PDB(59818@2026.10.24); name only
// ShaderRefBase, ShaderBody, EffectBase: STANDIN GUESS(low); placeholder bases that put the two secondary
// vtables at 0x10 and 0x90, where the adjustor thunks sit
#pragma once

#include <cstdint>

class ShaderRefBase
{
public:
    virtual ~ShaderRefBase();
    std::uint8_t unk08[0x8];
};

class ShaderBody
{
public:
    virtual ~ShaderBody();
    std::uint8_t unk08[0x78];
};

class EffectBase
{
public:
    virtual ~EffectBase();
    std::uint8_t unk08[0x88];
};

class BSImagespaceShader : public ShaderRefBase, public ShaderBody, public EffectBase
{
public:
    BSImagespaceShader();
    ~BSImagespaceShader() override;  // compared: the thunks at 0x15652f4 and 0x1565300
};
static_assert(sizeof(BSImagespaceShader) == 0x120, "BSImagespaceShader layout");
