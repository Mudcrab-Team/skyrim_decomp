// Origin: original reconstruction; destructor declaration informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSMoviePlayer.h, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Code origin: Stamped as a twin of matched 0x644660 (skyrim_shared/quest/BGSMoviePlayer_644660): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x622360 Owner622360::Function622360
#include "Owner622360.h"

// guess: same compiled code as matched 0x644660 apart from relocated fields; its role here is not established.
void Owner622360::Function622360()
{
 delete currentMoviePlayer;
 currentMoviePlayer = nullptr;
}
