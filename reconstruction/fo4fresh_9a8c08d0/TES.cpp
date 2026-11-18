// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:158 (TES::GetLandMaterialType)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:702 (TES::ResumeMasterFileLoads)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:695 (TES::CancelMasterFileLoads)
// TES, GetLandMaterialType, NiPoint3, TESLandTexture, GetLandTexture, GetHavokMaterialType, coord: GUESS(low)
// 0x1a59d0 TES::GetLandMaterialType
// 0x1a46a0 TES::ResumeMasterFileLoads
// 0x1a4670 TES::CancelMasterFileLoads
#include "TES.h"
unsigned int TES::GetLandMaterialType(const NiPoint3& coord)
{
    TESLandTexture* texture = GetLandTexture(coord);
    return texture ? texture->GetHavokMaterialType() : 0;
}

void TES::ResumeMasterFileLoads() { BGSDynamicPersistenceManager::instance->Resume(); }
void TES::CancelMasterFileLoads() { loader->CancelAllCellLoads(); BGSDynamicPersistenceManager::instance->Pause(); }
