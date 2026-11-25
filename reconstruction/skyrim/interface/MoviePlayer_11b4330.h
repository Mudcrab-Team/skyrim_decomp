// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: member names adapted from the sibling; the virtual slot and conversions checked against the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSMovie/MoviePlayer.cpp:164
// MoviePlayer, MoviePlayer::CalculateXOffset, MoviePlayer::GetScreenWidth: SIBLING(fo4-private@1b765c70, author-permission)
// MoviePlayer::unk00, unk01, unk02, unk03, unk04, unk05, unk06, unk07, unk08: GUESS(low); slot placeholders before GetScreenWidth
#pragma once

class MoviePlayer
{
public:
    virtual ~MoviePlayer();                   // 00
    virtual void unk01();                     // 01
    virtual void unk02();                     // 02
    virtual void unk03();                     // 03
    virtual void unk04();                     // 04
    virtual void unk05();                     // 05
    virtual void unk06();                     // 06
    virtual void unk07();                     // 07
    virtual void unk08();                     // 08
    virtual unsigned int GetScreenWidth();    // 09

    float CalculateXOffset(float afScale, unsigned int afWidth, bool abLetterBoxed);  // compared: 0x11b4330
};
