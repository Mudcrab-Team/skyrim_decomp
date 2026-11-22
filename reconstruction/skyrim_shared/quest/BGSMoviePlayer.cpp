// Code origin: Bodies for Unk_07, Unk_09, Unk_0B, Unk_0C and Function11b24e0 written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x644910 BGSMoviePlayer::Unk_09
// 0x644930 BGSMoviePlayer::Unk_0B
// 0x6448d0 BGSMoviePlayer::Unk_07
// 0x644940 BGSMoviePlayer::Unk_0C
// 0x645120 Leaf645120::Invoke
// 0x645130 Leaf645130::Invoke
// 0x644920 BGSMoviePlayer::Unk_0A
// 0x11b24e0 BGSMoviePlayer::Function11b24e0
#include "BGSMoviePlayer.h"
std::uint32_t BGSMoviePlayer::Unk_09() { return g_moviePlayerValue09; }
std::uint8_t BGSMoviePlayer::Unk_0B() { return g_moviePlayerFlag0B; }
void BGSMoviePlayer::Unk_07() { InitMoviePlayerObject(&g_moviePlayerObject); }
std::uint32_t BGSMoviePlayer::Unk_0C()
{
    Main* main = Main::singleton;
    if (main) {
        return main->unk28;
    }
    return 0;
}

// RVA 0x645120, 3 bytes
void BGSMoviePlayer::Unk_06()
{
}

// RVA 0x645130, 3 bytes
void BGSMoviePlayer::Unk_05()
{
}

// RVA 0x644920, 7 bytes
std::uint32_t BGSMoviePlayer::Unk_0A()
{
    return g_bgsMoviePlayerUnk;
}

extern void* g_moviePlayerCursorArg;
extern "C" __declspec(dllimport) void __stdcall MoviePlayerCursorOp(void* a_arg, int a_flag);

void BGSMoviePlayer::Function11b24e0(bool a_flag)
{
    if (a_flag) {
        MoviePlayerCursorOp(g_moviePlayerCursorArg, 0);
    }
}
