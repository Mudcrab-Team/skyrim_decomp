// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0xee4710 Leafee4710::Invoke
// 0xee4350 NiStream::Save1
// 0xee9550 NiStream::~NiStream
#include "NiStream.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
NiStream::NiStream()
{
}

// Unk_07: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void NiStream::Unk_07()
{
}

// Save1: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void NiStream::Save1(NiBinaryStream* a_stream)
{
    streamPtr2A0 = a_stream;
    Unk_10();
    streamPtr2A0 = nullptr;
}
