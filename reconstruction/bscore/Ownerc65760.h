// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0xec1710 (bscore/BSMemStorage): source copied, names replaced by placeholders.
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Ownerc65760: GUESS(low) STANDIN
// GetFileSize, member, padding, GetPosition, ~Ownerc65760, position, unk28: GUESS(low) STANDIN
#pragma once
#include "BSMemStorage.h"

class Ownerc65760
{
public:
    virtual std::uint32_t GetFileSize() const;
    virtual std::size_t GetPosition() const;
    Ownerc65760();
    virtual ~Ownerc65760();
    std::uint8_t padding[0x18];
    std::uint32_t member;
    std::uint32_t position;    // 24
    std::uint8_t  unk28[0x8];  // 28
};
static_assert(sizeof(Ownerc65760) == 0x30, "layout");
