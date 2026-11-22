// Source exposure: mixed (pinned image listing, sibling hint, community declarations).
// Code origin: existing sibling-adapted method plus original reconstruction of Function52d380.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, NiAVObject, NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESWaterSystem, WaterSystemHolder, WaterSystemSub, g_waterSystem, ReleaseWaterTarget, Function52d380: GUESS(low)
#pragma once
#include <cstdint>
class NiRTTI; class NiNode; class NiSwitchNode; class BSFadeNode; class BSMultiBoundNode; class BSGeometry; class NiTriStrips; class BSTriShape; class BSSegmentedTriShape; class BSSubIndexTriShape; class BSDynamicTriShape; class NiGeometry; class NiTriBasedGeom; class NiTriShape; class NiParticles; class BSLines; class bhkNiCollisionObject; class bhkBlendCollisionObject; class bhkAttachmentCollisionObject; class bhkRigidBody; class bhkLimitedHingeConstraint; class NiCloningProcess; class NiStream; class NiObjectGroup; class NiControllerManager; class NiUpdateData; class PerformOpFunc; class NiAlphaProperty; class BSFixedString; class NiCullingProcess; class NiAVObject; template<class T> class NiPointer;
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); unsigned refCount, pad; };
class NiObject : public NiRefObject { public:
virtual const NiRTTI*   GetRTTI() const;
virtual NiNode*                       AsNode();
virtual NiSwitchNode*                 AsSwitchNode();
virtual BSFadeNode*                   AsFadeNode();
virtual BSMultiBoundNode*             AsMultiBoundNode();
virtual BSGeometry*                   AsGeometry();
virtual NiTriStrips*                  AsTriStrips();
virtual BSTriShape*                   AsTriShape();
virtual BSSegmentedTriShape*          AsSegmentedTriShape();
virtual BSSubIndexTriShape*           AsSubIndexTriShape();
virtual BSDynamicTriShape*            AsDynamicTriShape();
virtual NiGeometry*                   AsNiGeometry();
virtual NiTriBasedGeom*               AsNiTriBasedGeom();
virtual NiTriShape*                   AsNiTriShape();
virtual NiParticles*                  AsParticlesGeom();
virtual BSLines*                      AsLinesGeom();
virtual bhkNiCollisionObject*         AsBhkNiCollisionObject();
virtual bhkBlendCollisionObject*      AsBhkBlendCollisionObject();
virtual bhkAttachmentCollisionObject* AsBhkAttachmentCollisionObject();
virtual bhkRigidBody*                 AsBhkRigidBody();
virtual bhkLimitedHingeConstraint*    AsBhkLimitedHingeConstraint();
virtual NiObject*                     CreateClone(NiCloningProcess& a_cloning);
virtual void                          LoadBinary(NiStream& a_stream);
virtual void                          LinkObject(NiStream& a_stream);
virtual bool                          RegisterStreamables(NiStream& a_stream);
virtual void                          SaveBinary(NiStream& a_stream);
virtual bool                          IsEqual(NiObject* a_object);
virtual void                          ProcessClone(NiCloningProcess& a_cloning);
virtual void                          PostLinkObject(NiStream& a_stream);
virtual bool                          StreamCanSkip();
virtual const NiRTTI*   GetStreamableRTTI() const;
virtual std::uint32_t   GetBlockAllocationSize() const;
virtual NiObjectGroup*  GetGroup() const;
virtual void                          SetGroup(NiObjectGroup* a_group);
virtual NiControllerManager*          AsNiControllerManager();
};
class NiObjectNET : public NiObject { public: const char* name; void* controllers; void** extra; unsigned short extraDataSize, maxSize; unsigned pad; };
class NiAVObject : public NiObjectNET { public:
virtual void UpdateControllers(NiUpdateData& a_data);
virtual void PerformOp(PerformOpFunc& a_func);
virtual void AttachProperty(NiAlphaProperty* a_property);
virtual void SetMaterialNeedsUpdate(bool a_needsUpdate);
virtual void SetDefaultMaterialNeedsUpdateFlag(bool a_flag);
virtual NiAVObject* GetObjectByName(const BSFixedString& a_name);
virtual void        SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);
virtual void        UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);
virtual void        UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);
virtual void        UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);
virtual void        UpdateWorldBound();
virtual void        UpdateWorldData(NiUpdateData* a_data);
virtual void        UpdateTransformAndBounds(NiUpdateData& a_data);
virtual void        PreAttachUpdate(NiNode* a_parent, NiUpdateData& a_data);
virtual void        PostAttachUpdate();
virtual void        OnVisible(NiCullingProcess& a_process);
 NiNode* parent; };
class NiNode : public NiAVObject { public:
virtual void AttachChild(NiAVObject* a_child, bool a_firstAvail = false);
virtual void InsertChildAt(std::uint32_t a_idx, NiAVObject* a_child);
virtual void DetachChild1(NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut);
virtual void DetachChild2(NiAVObject* a_child);
};
struct WaterSystemSub { std::uint8_t unknown00[0x18]; void* target; };
struct WaterSystemHolder { std::uint8_t unknown00[0x28]; WaterSystemSub* sub; };
extern WaterSystemHolder* g_waterSystem;
void ReleaseWaterTarget(void* a_target);
class TESWaterSystem { public: void RemoveWater(NiAVObject*); void RemoveLODWater(NiAVObject*, NiNode*); static void Function52d380(); };
