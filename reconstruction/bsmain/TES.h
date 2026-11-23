// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Code origin: original declarations with the cited sibling adaptations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:158 (TES::GetLandMaterialType)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:702 (TES::ResumeMasterFileLoads)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:695 (TES::CancelMasterFileLoads)
// TES::GetLandMaterialType, TES::ResumeMasterFileLoads, TES::CancelMasterFileLoads: SIBLING(fo4-private@1b765c70, author-permission)
// BGSDynamicPersistenceManager, instance, Pause, Resume, ExteriorCellLoader, loader, CancelAllCellLoads: GUESS(low)
// TES, GetLandMaterialType, NiPoint3, TESLandTexture, GetLandTexture, GetHavokMaterialType, coord: GUESS(low)
// TES::GetWorldSpace: GUESS(low); getter identified by the field it reads
// TESWorldSpace, worldSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00: GUESS(low); unaccessed region before the worldspace pointer
#pragma once

#include <cstddef>
class NiPoint3;
class TESWorldSpace;
class TESLandTexture { public: unsigned int GetHavokMaterialType(); };
class BGSDynamicPersistenceManager { public: static BGSDynamicPersistenceManager* instance; void Pause(); void Resume(); };
class ExteriorCellLoader { public: void CancelAllCellLoads(); };
extern ExteriorCellLoader* loader;
// Function1a2200, Function1a2200Arg, kind, a_flag: GUESS(low); the receiver, the argument type and the byte at 0x44 are unidentified
struct Function1a2200Arg { unsigned char unk00[0x44]; unsigned char kind; };
class TES {
public:
    TESWorldSpace* GetWorldSpace() const;
    bool Function1a2200(const Function1a2200Arg* a_arg, bool a_flag) const;
    void ResumeMasterFileLoads();
    void CancelMasterFileLoads();
    TESLandTexture* GetLandTexture(const NiPoint3& coord);
    unsigned int GetLandMaterialType(const NiPoint3& coord);
    TES* ScalarDeletingDestructor(unsigned a_flags);

    unsigned char unknown00[0x148];
    TESWorldSpace* worldSpace;
};
static_assert(offsetof(TES, worldSpace) == 0x148, "TES worldspace offset");

void DestroyTES(TES* a_world);
void FreeTES(TES* a_world, std::size_t a_size);
