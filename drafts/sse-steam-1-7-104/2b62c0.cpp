// Near miss: 0.0% | other
// TESObjectLAND::CreateDuplicateForm and SetAltered, build sse-steam-1-7-104.
//
// RVA 0x2a9130, 48 bytes (CreateDuplicateForm).
// RVA 0x2aa2e0, 56 bytes (SetAltered).
// Source exposure: mixed
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2b62c0 TESObjectLAND::~TESObjectLAND

#include "include/2b62c0/TESObjectLAND.h"

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

// Engineer p105: corrected secondary destructor slot and queued owning member.
// landThreadContext, LandContextScope, landObjectCount, saved: GUESS(low); retained TLS scope and instance count.
extern __declspec(thread) std::uint32_t landThreadContext;
extern std::uint32_t landObjectCount;
struct LandContextScope {
    std::uint32_t saved;
    LandContextScope() : saved(landThreadContext) { landThreadContext = 0x6c; }
    ~LandContextScope() { landThreadContext = saved; }
};
TESObjectLAND::TESObjectLAND() {}
TESObjectLAND::~TESObjectLAND()
{
    LandContextScope scope;
    ClearLand();
    --landObjectCount;
    TESForm::ClearData();
}
