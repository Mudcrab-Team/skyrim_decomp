// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkRefObject__VFTable; size 0x138
#pragma once

struct NiObject;
struct NiRefObject;
struct bhkRefObject;
struct bhkRefObject__VFTable {
    unsigned long long*(*dtor_0)(NiRefObject* , char);
    int (*Delete_8)(int (*)(unsigned long long, unsigned long long));
    long long (*GetRTTI_10)(void);
    long long (*AsNode_18)(void);
    long long (*AsSwitchNode_20)(void);
    long long (*AsFadeNode_28)(void);
    long long (*AsMultiBoundNode_30)(void);
    long long (*AsGeometry_38)(void);
    long long (*AsTriStrips_40)(void);
    long long (*AsTriShape_48)(void);
    long long (*AsSegmentedTriShape_50)(void);
    long long (*AsSubIndexTriShape_58)(void);
    long long (*AsDynamicTriShape_60)(void);
    long long (*AsNiGeometry_68)(void);
    long long (*AsNiTriBasedGeom_70)(void);
    long long (*AsNiTriShape_78)(void);
    long long (*AsParticlesGeom_80)(void);
    long long (*AsLinesGeom_88)(void);
    long long (*AsBhkNiCollisionObject_90)(void);
    long long (*AsBhkBlendCollisionObject_98)(void);
    long long (*AsBhkAttachmentCollisionObject_A0)(void);
    long long (*AsBhkRigidBody_A8)(void);
    long long (*AsBhkLimitedHingeConstraint_B0)(void);
    long long (*CreateClone_B8)(long long);
    void (*LoadBinary_C0)(void);
    void (*LinkObject_C8)(void);
    int (*RegisterStreamables_D0)(NiObject* , long long);
    void (*SaveBinary_D8)(void);
    void (*IsEqual_E0)(NiObject* , long long);
    long long (*ProcessClone_E8)(unsigned long long, long long);
    void (*PostLinkObject_F0)(void);
    char (*StreamCanSkip_F8)(void);
    int (*GetStreamableRTTI_100)(long long);
    long long (*GetBlockAllocationSize_108)(void);
    long long (*GetGroup_110)(void);
    void (*SetGroup_118)(void);
    long long (*AsNiControllerManager_120)(void);
    int (*Func37_128)(bhkRefObject* , long long);
    void (*Func38_130)(bhkRefObject* , char);
};
static_assert(sizeof(bhkRefObject__VFTable) == 312, "bhkRefObject__VFTable layout differs from the PDB");
