// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Sky/Sky.cpp:308
// Sky, Sky::UnloadAllTextures, Clouds, Clouds::RemoveTextures, Clouds::ClearTransTextures, Moon, Moon::RemoveTextures, Sun, Sun::RemoveTextures, Stars, Stars::UnloadGeometry: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to the members the body calls
// Sky::stars, Sky::sun, Sky::clouds, Sky::masser, Sky::secunda: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00: GUESS(low); the members before stars are unknown here
#pragma once

#include <cstdint>

class Clouds
{
public:
    void RemoveTextures();
    void ClearTransTextures();
};

class Moon
{
public:
    void RemoveTextures();
};

class Sun
{
public:
    void RemoveTextures();
};

class Stars
{
public:
    void UnloadGeometry();
};

class Sky
{
public:
    void UnloadAllTextures();

    std::uint8_t unk00[0x78];  // 00
    Stars*       stars;        // 78
    Sun*         sun;          // 80
    Clouds*      clouds;       // 88
    Moon*        masser;       // 90
    Moon*        secunda;      // 98
};
static_assert(sizeof(Sky) == 0xA0, "Sky stand-in size");
