// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSWaterShaderProperty, ForEachTexture, ForEachVisitor, Accept: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) SYMBOLS(tesv-2013-map)
// material: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; offset 0x78 read from the listing
// BSShaderMaterial, NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); BSShaderMaterial only holds the three texture slots the function walks
// propertyPad, materialPad, firstTexture, secondTexture, thirdTexture, GetSecond, GetThird: GUESS(low); padding and slots the function reads
#pragma once

#include <cstdint>
#include <cstddef>

class NiSourceTexture;

class BSShaderMaterial
{
public:
    unsigned char materialPad[0x40];
    NiSourceTexture* firstTexture;
    NiSourceTexture* secondTexture;
    NiSourceTexture* thirdTexture;
    NiSourceTexture* GetSecond() { return secondTexture; }
    NiSourceTexture* GetThird() { return thirdTexture; }
};

class BSWaterShaderProperty
{
public:
    class ForEachVisitor
    {
    public:
        virtual ~ForEachVisitor();
        virtual int Accept(NiSourceTexture* a_texture) = 0;
    };

    int ForEachTexture(ForEachVisitor& a_visitor);

    unsigned char propertyPad[0x78];
    BSShaderMaterial* material;
};
static_assert(offsetof(BSWaterShaderProperty, material) == 0x78, "material offset");

