// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpRayShapeCollectionFilter__VFTable; size 0x10
#pragma once

struct hkBool;
struct hkpRayShapeCollectionFilter_9e3dc0d7;
struct hkpShape;
struct hkpShapeContainer;
struct hkpShapeRayCastInput_bdbc339d;
struct hkpRayShapeCollectionFilter__VFTable {
    hkBool (*isCollisionEnabled_0)(hkpRayShapeCollectionFilter_9e3dc0d7* , hkpShapeRayCastInput_bdbc339d* , hkpShape* , hkpShapeContainer* , unsigned int);
    void (*dtor_8)(hkpRayShapeCollectionFilter_9e3dc0d7* );
};
static_assert(sizeof(hkpRayShapeCollectionFilter__VFTable) == 16, "hkpRayShapeCollectionFilter__VFTable layout differs from the PDB");
