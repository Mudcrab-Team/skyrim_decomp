// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: body adapted from the sibling function below; constants and conversions checked against the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSMovie/MoviePlayer.cpp:164
// 0x11b4330 MoviePlayer::CalculateXOffset
#include "MoviePlayer_11b4330.h"

// A letter-boxed movie is flush left; otherwise it is centred on the screen.
float MoviePlayer::CalculateXOffset(float afScale, unsigned int afWidth, bool abLetterBoxed)
{
    if (abLetterBoxed) {
        return 0.0f;
    }

    return ((float)GetScreenWidth() - ((float)afWidth * afScale)) * 0.5f;
}
