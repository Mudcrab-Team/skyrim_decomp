// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x340be0 TESGlobal::GetFormEditorID
// 0x340c00 TESGlobal::SetFormEditorID
#include "TESGlobal.h"

const char* TESGlobal::GetFormEditorID() const
{
    return formEditorID.c_str();
}

bool TESGlobal::SetFormEditorID(const char* a_str)
{
    formEditorID.Set(a_str, 0);
    return true;
}
