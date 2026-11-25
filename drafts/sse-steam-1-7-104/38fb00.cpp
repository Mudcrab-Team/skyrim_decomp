// Near miss: 0.0% | other
// BGSEquipSlot::InitializeData, build sse-steam-1-7-104.
//
// RVA 0x38f480, 8 bytes (InitializeData);
// Source exposure: mixed
// pinned image, with the class layout from the header beside this file. Names are from
// CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x38fb00 BGSEquipSlot::~BGSEquipSlot

#include "include/38fb00/BGSEquipSlot.h"

void BGSEquipSlot::InitializeData()
{
    flags = 0;
}

// EquipTLS, EquipScope, EquipArray, EquipArrayClear: GUESS(low); observed TLS slot and array cleanup.
extern __declspec(thread) std::uint32_t EquipTLS;
void EquipArrayClear(void*);
struct EquipScope {
    std::uint32_t saved;
    EquipScope() : saved(EquipTLS) { EquipTLS = 0x65; }
    ~EquipScope() { EquipTLS = saved; }
};
void BGSEquipSlot::ClearData()
{
    EquipScope scope;
    // array: GUESS(low); overlays the existing array storage.
    auto* array = &parentSlots;
    if (array->data) { EquipArrayClear(array); array->count = 0; }
}

// Engineer p105: ownership is a member lifetime, preserving the separate ClearData TLS scope.
BGSEquipSlot::BGSEquipSlot() {}
BGSEquipSlot::~BGSEquipSlot() { ClearData(); }
