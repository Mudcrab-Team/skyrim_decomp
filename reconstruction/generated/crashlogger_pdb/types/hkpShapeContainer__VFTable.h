// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeContainer__VFTable; size 0x38
#pragma once

struct hkpShape;
struct hkpShapeContainer;
struct hkpShapeContainer__VFTable {
    void (*dtor_0)(hkpShapeContainer* );
    int (*getNumChildShapes_8)(hkpShapeContainer* );
    unsigned int (*getFirstKey_10)(hkpShapeContainer* );
    unsigned int (*getNextKey_18)(hkpShapeContainer* , unsigned int);
    unsigned int (*getCollisionFilterInfo_20)(hkpShapeContainer* , unsigned int);
    hkpShape*(*getChildShape_28)(hkpShapeContainer* , unsigned int, char** );
    void (*isWeldingEnabled_30)(hkpShapeContainer* );
};
static_assert(sizeof(hkpShapeContainer__VFTable) == 56, "hkpShapeContainer__VFTable layout differs from the PDB");
