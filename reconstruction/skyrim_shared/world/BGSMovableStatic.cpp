// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x264444 BGSMovableStatic::dtor
// 0x2640a0 BGSMovableStatic::InitializeData
#include "BGSMovableStatic.h"

// The constructor is not compared: it is defined so that this unit emits the vftables and with
// them the destructor thunks. Its body is a minimal stand-in.
BGSMovableStatic::BGSMovableStatic()
{
}

BGSMovableStatic::~BGSMovableStatic()
{
}

void BGSMovableStatic::InitializeData()
{
    soundLoop = nullptr;
}
