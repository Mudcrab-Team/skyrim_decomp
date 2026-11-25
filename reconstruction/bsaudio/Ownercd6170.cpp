// Source exposure: mixed (community headers and the pinned image listing).
// Code origin: existing unit plus original reconstruction of BSAudio constructor and Functioncd4b80. Stamped as a twin of matched 0xcd4b70 (bsaudio/BSAudio): source copied, names replaced by placeholders.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// 0xcd6170 Ownercd6170::Shutdown
#include "Ownercd6170.h"

Ownercd6170::Ownercd6170()
    : field08(false), listener(nullptr)
{
}

// guess: same compiled code as matched 0xcd4b70 apart from relocated fields; its role here is not established.
void Ownercd6170::Shutdown()
{
    field08 = false;
}
