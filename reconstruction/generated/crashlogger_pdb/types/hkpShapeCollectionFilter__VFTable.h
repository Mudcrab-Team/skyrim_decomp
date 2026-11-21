// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeCollectionFilter__VFTable; size 0x20
#pragma once

struct hkAabb;
struct hkBool;
struct hkpBvTreeShape;
struct hkpCdBody_cce531ab;
struct hkpCollisionInput;
struct hkpShapeCollectionFilter;
struct hkpShapeContainer;
struct hkpShapeCollectionFilter__VFTable {
    char _pad_0[8];
    hkBool (*isCollisionEnabled_8)(hkpShapeCollectionFilter* , hkpCollisionInput* , hkpCdBody_cce531ab* , hkpCdBody_cce531ab* , hkpShapeContainer* , unsigned int);
    int (*numShapeKeyHitsLimitBreached_10)(hkpShapeCollectionFilter* , hkpCollisionInput* , hkpCdBody_cce531ab* , hkpCdBody_cce531ab* , hkpBvTreeShape* , hkAabb* , unsigned int* , int);
    void (*dtor_18)(hkpShapeCollectionFilter* );
};
static_assert(sizeof(hkpShapeCollectionFilter__VFTable) == 32, "hkpShapeCollectionFilter__VFTable layout differs from the PDB");
