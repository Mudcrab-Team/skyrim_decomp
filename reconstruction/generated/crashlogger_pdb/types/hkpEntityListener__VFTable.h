// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpEntityListener__VFTable; size 0x30
#pragma once

struct hkpEntityListener_a59fbb67;
struct hkpEntity_b3bc9432;
struct hkpEntityListener__VFTable {
    void (*dtor_0)(hkpEntityListener_a59fbb67* );
    void (*entityAddedCallback_8)(hkpEntityListener_a59fbb67* , hkpEntity_b3bc9432* );
    void (*entityRemovedCallback_10)(hkpEntityListener_a59fbb67* , hkpEntity_b3bc9432* );
    void (*entityShapeSetCallback_18)(hkpEntityListener_a59fbb67* , hkpEntity_b3bc9432* );
    void (*entitySetMotionTypeCallback_20)(hkpEntityListener_a59fbb67* , hkpEntity_b3bc9432* );
    void (*entityDeletedCallback_28)(hkpEntityListener_a59fbb67* , hkpEntity_b3bc9432* );
};
static_assert(sizeof(hkpEntityListener__VFTable) == 48, "hkpEntityListener__VFTable layout differs from the PDB");
