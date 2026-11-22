// Source exposure: mixed (pinned image and community declarations).
// Code origin: original reconstruction from the pinned image and community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x38f480 BGSEquipSlot::InitializeData
// 0x38fa70 BGSEquipSlot::IsHandEquipSlot
// 0x38f490 BGSEquipSlot::ClearData
#include "BGSEquipSlot.h"

void BGSEquipSlot::InitializeData()
{
    flags = 0;
}

namespace
{
// FileMemoryContext: GUESS(low); tracks the file allocation context across cleanup.
class FileMemoryContext
{
public:
    FileMemoryContext() : previous(g_memoryContext_tls_0x768)
    {
        constexpr std::uint32_t kFileMemoryContext = 0x65;
        g_memoryContext_tls_0x768 = kFileMemoryContext;
    }

    ~FileMemoryContext() { g_memoryContext_tls_0x768 = previous; }

private:
    std::uint32_t previous;
};
}

// Release the parent list in the file's allocation context.
void BGSEquipSlot::ClearData()
{
    FileMemoryContext context;
    parentSlots.Clear();
}

// Look for either of the default hand slots in the supplied slot's hierarchy.
bool BGSEquipSlot::IsHandEquipSlot(const BGSEquipSlot* a_slot)
{
    if (a_slot) {
        if (a_slot->ContainsSlot(BGSDefaultObjectManager::GetDefaultObject(BGSDefaultObjectManager::kLeftHandEquip)) ||
            a_slot->ContainsSlot(BGSDefaultObjectManager::GetDefaultObject(BGSDefaultObjectManager::kRightHandEquip))) {
            return true;
        }
    }
    return false;
}
