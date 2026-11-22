// Source exposure: mixed (pinned listing, community names and the labelled sibling sources).
// Code origin: original reconstruction and the sibling adaptations cited below.
// Adapted bodies: GetLandMaterialType, ResumeMasterFileLoads and CancelMasterFileLoads (author-permission).
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:158 (TES::GetLandMaterialType)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:702 (TES::ResumeMasterFileLoads)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:695 (TES::CancelMasterFileLoads)
// TES::GetLandMaterialType, TES::ResumeMasterFileLoads, TES::CancelMasterFileLoads: SIBLING(fo4-private@1b765c70, author-permission)
// TES deleting destructor owner and allocation size: CRASHLOGGER_PDB(59818@2026.10.24)
// TES::ScalarDeletingDestructor, DestroyTES, FreeTES: GUESS(low) STANDIN
// Function1a2200, Function1a2200Arg: GUESS(low)
// 0x1a59d0 TES::GetLandMaterialType
// 0x1a46a0 TES::ResumeMasterFileLoads
// 0x1a4670 TES::CancelMasterFileLoads
// 0x1a2200 TES::Function1a2200
// 0x1b4660 TES::ScalarDeletingDestructor
#include "TES.h"

namespace {
constexpr unsigned kReleaseStorage = 1u;
constexpr std::size_t kTESAllocationSize = 704;
}
unsigned int TES::GetLandMaterialType(const NiPoint3& coord)
{
    TESLandTexture* texture = GetLandTexture(coord);
    return texture ? texture->GetHavokMaterialType() : 0;
}

void TES::ResumeMasterFileLoads() { BGSDynamicPersistenceManager::instance->Resume(); }
void TES::CancelMasterFileLoads() { loader->CancelAllCellLoads(); BGSDynamicPersistenceManager::instance->Pause(); }

bool TES::Function1a2200(const Function1a2200Arg* a_arg, bool a_flag) const
{
    if (!a_arg) {
        return false;
    }
    switch (a_arg->kind) {
    case 3:
    case 4:
    case 5:
        return !a_flag;
    case 6:
    case 7:
        return true;
    default:
        return false;
    }
}

// Run the complete destructor, then release the allocation when requested.
TES* TES::ScalarDeletingDestructor(unsigned a_flags)
{
    DestroyTES(this);
    if (a_flags & kReleaseStorage) {
        FreeTES(this, kTESAllocationSize);
    }
    return this;
}
