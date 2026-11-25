// Source exposure: mixed (sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESContainer.cpp:78
// Unk1461b10, Unk1461b10Base, Unk1461b10::~Unk1461b10, Release: GUESS(low); the class and its base are unidentified, only the destructor shape is known
#pragma once

#include <cstdint>

class Unk1461b10Base
{
public:
    virtual ~Unk1461b10Base() {}  // 00
};

class Unk1461b10 : public Unk1461b10Base
{
public:
    ~Unk1461b10() override;  // 00, compared: 0x1461b10

    void Release();

    std::uint8_t unknown08[0x10];  // 08
};
