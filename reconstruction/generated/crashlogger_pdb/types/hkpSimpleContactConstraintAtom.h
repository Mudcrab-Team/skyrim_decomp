// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSimpleContactConstraintAtom; size 0x30
#pragma once

#include "hkEnum_hkpConstraintAtom__AtomType_uint16.h"
#include "hkpSimpleContactConstraintDataInfo.h"
struct hkpSimpleContactConstraintAtom {
    hkEnum_hkpConstraintAtom__AtomType_uint16 m_type_0;
    unsigned short m_sizeOfAllAtoms_2;
    unsigned short m_numContactPoints_4;
    unsigned short m_numReservedContactPoints_6;
    unsigned char m_numUserDatasForBodyA_8;
    unsigned char m_numUserDatasForBodyB_9;
    unsigned char m_contactPointPropertiesStriding_A;
    char _pad_B;
    unsigned short m_maxNumContactPoints_C;
    char _pad_E[2];
    hkpSimpleContactConstraintDataInfo m_info_10;
};
static_assert(sizeof(hkpSimpleContactConstraintAtom) == 48, "hkpSimpleContactConstraintAtom layout differs from the PDB");
