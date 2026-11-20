// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x2a9130 TESObjectLAND::CreateDuplicateForm
// 0x2aa2e0 TESObjectLAND::SetAltered
#include "TESObjectLAND.h"

TESForm* TESObjectLAND::CreateDuplicateForm(bool a_createEditorID, void* a_arg2)
{
    (void)a_createEditorID;
    return dynamic_cast<TESObjectLAND*>(TESForm::CreateDuplicateForm(false, a_arg2));
}

void TESObjectLAND::SetAltered(bool a_set)
{
    TESForm::SetAltered(a_set);
    if (a_set && parentCell) {
        parentCell->SetAltered(true);
    }
}
