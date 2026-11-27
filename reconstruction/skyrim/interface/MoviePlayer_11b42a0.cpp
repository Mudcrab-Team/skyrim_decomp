// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x11b42a0 MoviePlayer::WaitForSequenceToBegin
// Adapted bodies: none
#include "MoviePlayer_11b42a0.h"

// Poll with 1 ms sleeps until the movie sequence thread finishes or the current movie clears unk28.
void MoviePlayer::WaitForSequenceToBegin()
{
    while (sequenceThreadHandle && (!currentMovie || currentMovie->unk28)) {
        Sleep(1);
    }
}
