// Origin: original reconstruction; destructor declaration informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSMoviePlayer.h, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x644660 BGSMoviePlayer::Function644660
#include "BGSMoviePlayer.h"
void BGSMoviePlayer::Function644660()
{
 delete currentMoviePlayer;
 currentMoviePlayer = nullptr;
}
