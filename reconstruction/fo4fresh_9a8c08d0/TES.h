// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:158 (TES::GetLandMaterialType)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:702 (TES::ResumeMasterFileLoads)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:695 (TES::CancelMasterFileLoads)
// BGSDynamicPersistenceManager, instance, Pause, Resume, ExteriorCellLoader, loader, CancelAllCellLoads: GUESS(low)
// TES, GetLandMaterialType, NiPoint3, TESLandTexture, GetLandTexture, GetHavokMaterialType, coord: GUESS(low)
#pragma once
class NiPoint3;
class TESLandTexture { public: unsigned int GetHavokMaterialType(); };
class BGSDynamicPersistenceManager { public: static BGSDynamicPersistenceManager* instance; void Pause(); void Resume(); };
class ExteriorCellLoader { public: void CancelAllCellLoads(); };
extern ExteriorCellLoader* loader;
class TES { public: void ResumeMasterFileLoads(); void CancelMasterFileLoads(); public: TESLandTexture* GetLandTexture(const NiPoint3& coord); unsigned int GetLandMaterialType(const NiPoint3& coord); };
