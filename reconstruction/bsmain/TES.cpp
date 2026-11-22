// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:158 (TES::GetLandMaterialType)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:702 (TES::ResumeMasterFileLoads)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:695 (TES::CancelMasterFileLoads)
// TES, GetLandMaterialType, NiPoint3, TESLandTexture, GetLandTexture, GetHavokMaterialType, coord: GUESS(low)
// 0x1a59d0 TES::GetLandMaterialType
// 0x1a46a0 TES::ResumeMasterFileLoads
// 0x1a4670 TES::CancelMasterFileLoads
// Code origin: sibling bodies as cited; Function1a2200 original from the listing only
// 0x1a2200 TES::Function1a2200
// Adapted bodies: GetLandMaterialType, ResumeMasterFileLoads, CancelMasterFileLoads from fo4-private@1b765c70 (author-permission)
// Function1a2200, Function1a2200Arg: GUESS(low)
#include "TES.h"
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
