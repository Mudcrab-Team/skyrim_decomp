// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiCullingProcess_vtbl; size 0xc8
#pragma once
struct NiCullingProcess_vtbl {
    char32_t*(*GetRTTI)(void);
    char32_t*(*GetAsNiNode)(void);
    char32_t*(*GetAsNiSwitchNode)(void);
    char32_t*(*GetAsBSFadeNode)(void);
    char32_t*(*GetAsBSMultiBoundNode)(void);
    char32_t*(*GetAsBSGeometry)(void);
    char32_t*(*GetAsNiTriStrips)(void);
    char32_t*(*GetAsBSTriShape)(void);
    char32_t*(*GetAsBSSegmentedTriShape)(void);
    char32_t*(*GetAsBSSubIndexTriShape)(void);
    char32_t*(*GetAsBSDynamicTriShape)(void);
    char32_t*(*GetAsNiGeometry)(void);
    char32_t*(*GetAsNiTriBasedGeom)(void);
    char32_t*(*GetAsNiTriShape)(void);
    char32_t*(*GetAsNiParticles)(void);
    char32_t*(*GetAsBSLines)(void);
    char32_t*(*GetAsBhkNiCollisionObject)(void);
    char32_t*(*GetAsBhkBlendCollisionObject)(void);
    char32_t*(*GetAsBhkAttachmentCollisionObject)(void);
    char32_t*(*GetAsBhkRigidBody)(void);
    char32_t*(*GetAsBhkLimitedHingeConstraint)(void);
    void (*_dtor_NiCullingProcess)(void);
    void (*Process1)(char32_t* , int);
    void (*Process2)(char32_t* , char32_t* , char32_t* );
    void (*AppendVirtual)(char32_t* , int);
};
static_assert(sizeof(NiCullingProcess_vtbl) == 200, "NiCullingProcess_vtbl layout differs from the PDB");
