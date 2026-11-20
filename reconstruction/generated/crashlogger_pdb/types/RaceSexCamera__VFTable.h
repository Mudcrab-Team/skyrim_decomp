// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RaceSexCamera__VFTable; size 0x18
#pragma once

struct PlayerCamera;
struct TESCamera_ba12c162;
struct RaceSexCamera__VFTable {
    long long (*dtor_0)(TESCamera_ba12c162* , char);
    int (*SetCameraRoot_8)(TESCamera_ba12c162* , long long);
    int (*Update_10)(PlayerCamera* );
};
static_assert(sizeof(RaceSexCamera__VFTable) == 24, "RaceSexCamera__VFTable layout differs from the PDB");
