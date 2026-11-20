// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x1daad0 BGSOverridePackCollection::InitializeDataComponent
// 0x1db070 BGSOverridePackCollection::~BGSOverridePackCollection
#include "BGSOverridePackCollection.h"

BGSOverridePackCollection::BGSOverridePackCollection()
{
}

BGSOverridePackCollection::~BGSOverridePackCollection()
{
}

void BGSOverridePackCollection::InitializeDataComponent()
{
    spectatorOverRidePackList = nullptr;
    observeCorpseOverRidePackList = nullptr;
    guardWarnOverRidePackList = nullptr;
    enterCombatOverRidePackList = nullptr;
}

// BGSOverridePackCollection::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BGSOverridePackCollection::ClearDataComponent()
{
}
