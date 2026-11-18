// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsidlecollection.cpp:159
// 0x1d76e0 BGSIdleCollection::InitializeDataComponent
// 0x1d75f0 BGSIdleCollection::Ctor
#include "BGSIdleCollection.h"

BGSIdleCollection::BGSIdleCollection()
{
    InitializeDataComponent();
}

void BGSIdleCollection::InitializeDataComponent()
{
    idleFlags = 0;
    idleCount = 0;
    idles = nullptr;
    timerCheckForIdle = 0.0f;
}
