// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x2a8e30 TESImageSpaceModifier::GetFormEditorID
// 0x2a8e70 TESImageSpaceModifier::SetFormEditorID
// 0x2a8df0 TESImageSpaceModifier::~TESImageSpaceModifier
#include "TESImageSpaceModifier.h"

// The constructor is not compared: it is defined so that this unit emits the vftable and with it
// the deleting destructor.
TESImageSpaceModifier::TESImageSpaceModifier()
{
}

const char* TESImageSpaceModifier::GetFormEditorID() const
{
    return formEditorID.c_str();
}

bool TESImageSpaceModifier::SetFormEditorID(const char* a_str)
{
    formEditorID.Set(a_str, 0);
    return true;
}
