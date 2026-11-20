// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCamera__VFTable; size 0x18
#pragma once

struct PlayerCamera;
struct TESCamera_ba12c162;
struct TESCamera__VFTable {
    long long (*dtor_0)(TESCamera_ba12c162* , char);
    int (*SetCameraRoot_8)(TESCamera_ba12c162* , long long);
    int (*Update_10)(PlayerCamera* );
};
static_assert(sizeof(TESCamera__VFTable) == 24, "TESCamera__VFTable layout differs from the PDB");
