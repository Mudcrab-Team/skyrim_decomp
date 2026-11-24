// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Code origin: declarations generated from a tools/skeleton.py skeleton and extended by hand from the local listings; globals and helper callees are named guesses.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// BGSMoviePlayer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// MoviePlayer: STANDIN EXE_RTTI
// BGSMoviePlayer::Unk_06, BGSMoviePlayer::Unk_05, BGSMoviePlayer::Unk_0A, BGSMoviePlayer::Unk_07, BGSMoviePlayer::Unk_09, BGSMoviePlayer::Unk_0B, BGSMoviePlayer::Unk_0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MoviePlayer::~MoviePlayer, unknown08, unknown58: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// unk00, unk08, unk10, unk18, unk20: GUESS(low); storage before unk28, not read by the compared code
#pragma once
#include <cstddef>
#include <cstdint>

namespace ReconstructedBGSMoviePlayer {


#include <cstdint>
#include <cstddef>

class MoviePlayer
{
public:
    virtual ~MoviePlayer() = default;
    std::uint8_t unknown08[0x50];  // 08
};
static_assert(sizeof(MoviePlayer) == 0x58, "MoviePlayer size");

// g_moviePlayerValue09: GUESS(low); the dword at address 0x33363c4 that Unk_09 returns.
// g_moviePlayerFlag0B: GUESS(low); the byte at address 0x3336400 that Unk_0B returns.
// g_moviePlayerObject: GUESS(low); the object at address 0x3331f40 passed to the callee in Unk_07.
// InitMoviePlayerObject: GUESS(low); address 0x1009cf0, called by Unk_07 with the global object.
// Main::singleton: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); global at address 0x3230530
// unk28: GUESS(low); member of Main read by Unk_0C.
// g_bgsMoviePlayerUnk: GUESS(low); the dword at address 0x33363c8 that Unk_0A returns.
extern std::uint32_t g_bgsMoviePlayerUnk;
extern std::uint32_t g_moviePlayerValue09;
extern std::uint8_t g_moviePlayerFlag0B;
extern char g_moviePlayerObject;
void InitMoviePlayerObject(void* a_object);
class Main {
public:
    static Main* singleton;
    std::uint64_t unk00;  // 00
    std::uint64_t unk08;  // 08
    std::uint64_t unk10;  // 10
    std::uint64_t unk18;  // 18
    std::uint64_t unk20;  // 20
    std::uint32_t unk28;           // 28
};

// GetById, SourceType, LocalType, field30: GUESS(low); stand-ins for the objects the Unk_01 body uses
class SourceType
{
public:
    std::uint8_t unknown00[0x30];  // 00
    std::uint32_t field30;  // 30
};
SourceType* GetById(unsigned a_id);
class LocalType
{
public:
    LocalType(std::uint32_t* a_value);
    void Release(unsigned a_flag);
};

class BGSMoviePlayer : public MoviePlayer
{
public:
    static void Function6448f0();

public:
    virtual void Unk_06();  // compared: 0x645120
    virtual void Unk_05();  // compared: 0x645130
    virtual std::uint32_t Unk_0A();  // compared: 0x644920
    virtual void Unk_07();  // compared: 0x6448d0
    virtual std::uint32_t Unk_09();  // compared: 0x644910
    virtual std::uint8_t Unk_0B();  // compared: 0x644930
    virtual std::uint32_t Unk_0C();  // compared: 0x644940
    void Function11b24e0(bool a_flag);
    void Unk_01();  // compared: 0x6447f0

    // keeping every offset and the size check true.
    std::uint8_t unknown58[0x68];  // 58
};
static_assert(sizeof(BGSMoviePlayer) == 0xC0, "BGSMoviePlayer size");

class Renderer;
extern Renderer unknownRenderer3331f40;

}
