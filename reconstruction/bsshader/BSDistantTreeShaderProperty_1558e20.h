// Source exposure: mixed (pinned image, community declarations and permitted symbol prototypes).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSDistantTreeShaderProperty, ForEachTexture: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// BSShaderProperty, ForEachVisitor, Accept, NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// spTexture: SYMBOLS(fo4-pdb); pointer array placed at the observed target offset.
// unknownPrefix: GUESS(low); unaccessed storage, not a complete base layout.
#pragma once
#include <cstddef>
#include <cstdint>

class NiSourceTexture;
class BSShaderProperty
{
public:
    class ForEachVisitor
    {
    public:
        virtual ~ForEachVisitor();
        virtual std::int32_t Accept(NiSourceTexture* texture) = 0;
    };
};

class BSDistantTreeShaderProperty
{
public:
    std::int32_t ForEachTexture(BSShaderProperty::ForEachVisitor& visitor);
    unsigned char unknownPrefix[0x90];
    NiSourceTexture* spTexture[1];
};
static_assert(offsetof(BSDistantTreeShaderProperty, spTexture) == 0x90, "texture offset");
