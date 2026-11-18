// Source exposure: mixed (public complete data declarations and independent primary RTTI/call operand bindings).
// Code origin: public data-only adaptations and ordinary compiler deleting-wrapper emission. No external implementation body reused; complete destructors remain external.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{F/FirstPersonState.h,F/FreeCameraState.h,T/ThirdPersonState.h,N/NiPoint2.h,N/NiPoint3.h,N/NiQuaternion.h,C/Color.h,S/Setting.h,G/GFxValue.h,G/GPtr.h,H/HUDObject.h,H/HUDChargeMeter.h,B/BSTempEffectDebris.h,B/BGSPackageDataLocation.h,B/BGSNamedPackageData.h,B/BGSPackageDataPointerTemplate.h,B/BGSTextureModel.h}; MIT.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/{A/AutoVanityState.h,F/FurnitureCameraState.h,C/CombatPath.h}; GPL-3.0.
// FirstPersonState, FreeCameraState, ThirdPersonState, Setting, GFxValue, HUDObject, HUDChargeMeter, BSTempEffectDebris, BGSPackageDataLocation, BGSNamedPackageData, BGSPackageDataPointerTemplate, BGSTextureModel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AutoVanityState, FurnitureCameraState, CombatPath: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// New storage class names, fields and pointee names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "../../bssystem/QueuedFileDataStorageLayout.h"
#include "../ai/combat/CombatPathRequestPointerStorageLayout.h"
#include "../../unmapped/represented/BSTempEffectLayout.h"
namespace ResearchLayouts {
class CameraObjectPointeeLayout;
class CameraNodePointeeLayout;
class DebrisObjectPointeeLayout;
class PackageLocationPointeeLayout;
class HudMovieViewPointeeLayout;
class GfxObjectInterfacePointeeLayout;
struct CameraPoint2DataStorageLayout { float x,y; };
struct CameraQuaternionDataStorageLayout { float w,x,y,z; };
struct SettingColorDataStorageLayout { std::uint8_t red,green,blue,alpha; };
class FirstPersonCameraDataStorageLayout : public CameraStateDataStorageLayout, public PlayerInputDataStorageLayout {
public:
    ~FirstPersonCameraDataStorageLayout() override;
    NiPoint3 lastPosition,lastFrameSpringVelocity,dampeningOffset;
    CameraObjectPointeeLayout* firstPersonCameraObj;
    CameraNodePointeeLayout* firstPersonFOVControl;
    float sittingRotation,unk6C,unk70,currentPitchOffset,targetPitchOffset,unk7C;
    std::uint32_t unk80;
    bool cameraOverride,cameraPitchOverride;
    std::uint16_t unk86;
    std::uint64_t unk88;
};
class FreeCameraDataStorageLayout : public CameraStateDataStorageLayout, public PlayerInputDataStorageLayout {
public:
    ~FreeCameraDataStorageLayout() override;
    NiPoint3 translation;
    CameraPoint2DataStorageLayout rotation,zUpDown;
    std::int16_t verticalDirection;
    bool useRunSpeed,lockToZPlane;
};
class ThirdPersonCameraDataStorageLayout : public CameraStateDataStorageLayout, public PlayerInputDataStorageLayout {
public:
    ~ThirdPersonCameraDataStorageLayout() override;
    CameraObjectPointeeLayout* thirdPersonCameraObj;
    CameraNodePointeeLayout* thirdPersonFOVControl;
    NiPoint3 translation;
    CameraQuaternionDataStorageLayout rotation;
    NiPoint3 posOffsetExpected,posOffsetActual;
    float targetZoomOffset,currentZoomOffset,targetYaw,currentYaw,savedZoomOffset,pitchZoomOffset,unk8C;
    NiPoint3 collisionPos;
    float collisionPosValid;
    std::uint64_t unkA0;
    const char* animatedBoneName;
    CameraQuaternionDataStorageLayout animationRotation;
    std::uint64_t unkC0,unkC8;
    std::uint32_t unkD0;
    CameraPoint2DataStorageLayout freeRotation;
    bool freeRotationEnabled,stateNotActive;
    std::uint16_t unkDE;
    bool toggleAnimCam,applyOffsets;
    std::uint16_t unkE2;
    std::uint32_t unkE4;
};
class AutoVanityCameraDataStorageLayout : public CameraStateDataStorageLayout {
public:
    ~AutoVanityCameraDataStorageLayout() override;
    float autoVanityRot;
};
class FurnitureCameraDataStorageLayout : public CameraStateDataStorageLayout {
public:
    ~FurnitureCameraDataStorageLayout() override;
    std::uint32_t unk20;
    NiPoint3 unk24;
    std::uint64_t unk30;
    std::uint32_t unk38;
    std::uint16_t unk3C,unk3E;
};
union SettingValueDataStorageLayout { bool b;float f;std::int32_t i;SettingColorDataStorageLayout r;char* s;std::uint32_t u; };
class SettingDataStorageLayout {
public:
    virtual ~SettingDataStorageLayout();
    SettingValueDataStorageLayout data;
    char* name;
};
union GfxValueUnionDataStorageLayout { double number;bool boolean;const char* string;const char** managedString;const wchar_t* wideString;const wchar_t** managedWideString;void* obj; };
struct GfxValueDataStorageLayout { GfxObjectInterfacePointeeLayout* objectInterface;std::uint32_t type;GfxValueUnionDataStorageLayout value; };
class HudObjectDataStorageLayout {
public:
    virtual ~HudObjectDataStorageLayout();
    HudMovieViewPointeeLayout* view;
    GfxValueDataStorageLayout root;
};
class HudChargeMeterDataStorageLayout : public HudObjectDataStorageLayout {
public:
    ~HudChargeMeterDataStorageLayout() override;
    float unk28,unk2C;
};
class DebrisEffectDataStorageLayout : public BSTempEffectLayout {
public:
    ~DebrisEffectDataStorageLayout() override;
    DebrisObjectPointeeLayout* debris3D;
    const char* debrisFileName;
    bool unk40;
    std::uint8_t unk41;
};
union NamedPackageValueDataStorageLayout { bool b;std::uint32_t i;float f;void* p; };
class PackageLocationDataStorageLayout : public RemainingVptrContractLayout<8100>, public RemainingVptrContractLayout<8101> {
public:
    ~PackageLocationDataStorageLayout() override;
    NamedPackageValueDataStorageLayout data;
    PackageLocationPointeeLayout* pointer;
};
class CombatPathCompleteDataStorageLayout : public CombatPathDataStorageLayout { public: ~CombatPathCompleteDataStorageLayout() override; };
class CellEventCompleteDataStorageLayout : public CellEventSourceDataStorageLayout { public: ~CellEventCompleteDataStorageLayout() override; };
class TextureModelCompleteDataStorageLayout : public ModelComponentLayout {
public:
    ~TextureModelCompleteDataStorageLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(CameraPoint2DataStorageLayout)==8,"complete public data storage");
static_assert(sizeof(CameraQuaternionDataStorageLayout)==16,"complete public data storage");
static_assert(sizeof(SettingColorDataStorageLayout)==4,"complete public data storage");
static_assert(sizeof(FirstPersonCameraDataStorageLayout)==144,"complete public data storage");
static_assert(sizeof(FreeCameraDataStorageLayout)==80,"complete public data storage");
static_assert(sizeof(ThirdPersonCameraDataStorageLayout)==232,"complete public data storage");
static_assert(sizeof(AutoVanityCameraDataStorageLayout)==40,"complete public data storage");
static_assert(sizeof(FurnitureCameraDataStorageLayout)==64,"complete public data storage");
static_assert(sizeof(SettingValueDataStorageLayout)==8,"complete public data storage");
static_assert(sizeof(SettingDataStorageLayout)==24,"complete public data storage");
static_assert(sizeof(GfxValueUnionDataStorageLayout)==8,"complete public data storage");
static_assert(sizeof(GfxValueDataStorageLayout)==24,"complete public data storage");
static_assert(sizeof(HudObjectDataStorageLayout)==40,"complete public data storage");
static_assert(sizeof(HudChargeMeterDataStorageLayout)==48,"complete public data storage");
static_assert(sizeof(DebrisEffectDataStorageLayout)==72,"complete public data storage");
static_assert(sizeof(NamedPackageValueDataStorageLayout)==8,"complete public data storage");
static_assert(sizeof(PackageLocationDataStorageLayout)==32,"complete public data storage");
static_assert(sizeof(CombatPathCompleteDataStorageLayout)==56,"complete public data storage");
static_assert(sizeof(CellEventCompleteDataStorageLayout)==96,"complete public data storage");
static_assert(sizeof(TextureModelCompleteDataStorageLayout)==40,"complete public data storage");
static_assert(offsetof(CameraPoint2DataStorageLayout,x)==0,"public field offset");
static_assert(offsetof(CameraPoint2DataStorageLayout,y)==4,"public field offset");
static_assert(offsetof(CameraQuaternionDataStorageLayout,w)==0,"public field offset");
static_assert(offsetof(CameraQuaternionDataStorageLayout,x)==4,"public field offset");
static_assert(offsetof(CameraQuaternionDataStorageLayout,y)==8,"public field offset");
static_assert(offsetof(CameraQuaternionDataStorageLayout,z)==12,"public field offset");
static_assert(offsetof(SettingColorDataStorageLayout,red)==0,"public field offset");
static_assert(offsetof(SettingColorDataStorageLayout,green)==1,"public field offset");
static_assert(offsetof(SettingColorDataStorageLayout,blue)==2,"public field offset");
static_assert(offsetof(SettingColorDataStorageLayout,alpha)==3,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,lastPosition)==48,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,lastFrameSpringVelocity)==60,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,dampeningOffset)==72,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,firstPersonCameraObj)==88,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,firstPersonFOVControl)==96,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,sittingRotation)==104,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,unk6C)==108,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,unk70)==112,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,currentPitchOffset)==116,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,targetPitchOffset)==120,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,unk7C)==124,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,unk80)==128,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,cameraOverride)==132,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,cameraPitchOverride)==133,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,unk86)==134,"public field offset");
static_assert(offsetof(FirstPersonCameraDataStorageLayout,unk88)==136,"public field offset");
static_assert(offsetof(FreeCameraDataStorageLayout,translation)==48,"public field offset");
static_assert(offsetof(FreeCameraDataStorageLayout,rotation)==60,"public field offset");
static_assert(offsetof(FreeCameraDataStorageLayout,zUpDown)==68,"public field offset");
static_assert(offsetof(FreeCameraDataStorageLayout,verticalDirection)==76,"public field offset");
static_assert(offsetof(FreeCameraDataStorageLayout,useRunSpeed)==78,"public field offset");
static_assert(offsetof(FreeCameraDataStorageLayout,lockToZPlane)==79,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,thirdPersonCameraObj)==48,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,thirdPersonFOVControl)==56,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,translation)==64,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,rotation)==76,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,posOffsetExpected)==92,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,posOffsetActual)==104,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,targetZoomOffset)==116,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,currentZoomOffset)==120,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,targetYaw)==124,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,currentYaw)==128,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,savedZoomOffset)==132,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,pitchZoomOffset)==136,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,unk8C)==140,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,collisionPos)==144,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,collisionPosValid)==156,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,unkA0)==160,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,animatedBoneName)==168,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,animationRotation)==176,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,unkC0)==192,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,unkC8)==200,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,unkD0)==208,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,freeRotation)==212,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,freeRotationEnabled)==220,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,stateNotActive)==221,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,unkDE)==222,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,toggleAnimCam)==224,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,applyOffsets)==225,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,unkE2)==226,"public field offset");
static_assert(offsetof(ThirdPersonCameraDataStorageLayout,unkE4)==228,"public field offset");
static_assert(offsetof(AutoVanityCameraDataStorageLayout,autoVanityRot)==32,"public field offset");
static_assert(offsetof(FurnitureCameraDataStorageLayout,unk20)==32,"public field offset");
static_assert(offsetof(FurnitureCameraDataStorageLayout,unk24)==36,"public field offset");
static_assert(offsetof(FurnitureCameraDataStorageLayout,unk30)==48,"public field offset");
static_assert(offsetof(FurnitureCameraDataStorageLayout,unk38)==56,"public field offset");
static_assert(offsetof(FurnitureCameraDataStorageLayout,unk3C)==60,"public field offset");
static_assert(offsetof(FurnitureCameraDataStorageLayout,unk3E)==62,"public field offset");
static_assert(offsetof(SettingDataStorageLayout,data)==8,"public field offset");
static_assert(offsetof(SettingDataStorageLayout,name)==16,"public field offset");
static_assert(offsetof(GfxValueDataStorageLayout,objectInterface)==0,"public field offset");
static_assert(offsetof(GfxValueDataStorageLayout,type)==8,"public field offset");
static_assert(offsetof(GfxValueDataStorageLayout,value)==16,"public field offset");
static_assert(offsetof(HudObjectDataStorageLayout,view)==8,"public field offset");
static_assert(offsetof(HudObjectDataStorageLayout,root)==16,"public field offset");
static_assert(offsetof(HudChargeMeterDataStorageLayout,unk28)==40,"public field offset");
static_assert(offsetof(HudChargeMeterDataStorageLayout,unk2C)==44,"public field offset");
static_assert(offsetof(DebrisEffectDataStorageLayout,debris3D)==48,"public field offset");
static_assert(offsetof(DebrisEffectDataStorageLayout,debrisFileName)==56,"public field offset");
static_assert(offsetof(DebrisEffectDataStorageLayout,unk40)==64,"public field offset");
static_assert(offsetof(DebrisEffectDataStorageLayout,unk41)==65,"public field offset");
static_assert(offsetof(PackageLocationDataStorageLayout,data)==16,"public field offset");
static_assert(offsetof(PackageLocationDataStorageLayout,pointer)==24,"public field offset");
static_assert(offsetof(SettingValueDataStorageLayout,b)==0,"public union overlap");
static_assert(offsetof(SettingValueDataStorageLayout,f)==0,"public union overlap");
static_assert(offsetof(SettingValueDataStorageLayout,i)==0,"public union overlap");
static_assert(offsetof(SettingValueDataStorageLayout,r)==0,"public union overlap");
static_assert(offsetof(SettingValueDataStorageLayout,s)==0,"public union overlap");
static_assert(offsetof(SettingValueDataStorageLayout,u)==0,"public union overlap");
static_assert(offsetof(GfxValueUnionDataStorageLayout,number)==0,"public union overlap");
static_assert(offsetof(GfxValueUnionDataStorageLayout,boolean)==0,"public union overlap");
static_assert(offsetof(GfxValueUnionDataStorageLayout,string)==0,"public union overlap");
static_assert(offsetof(GfxValueUnionDataStorageLayout,managedString)==0,"public union overlap");
static_assert(offsetof(GfxValueUnionDataStorageLayout,wideString)==0,"public union overlap");
static_assert(offsetof(GfxValueUnionDataStorageLayout,managedWideString)==0,"public union overlap");
static_assert(offsetof(GfxValueUnionDataStorageLayout,obj)==0,"public union overlap");
static_assert(offsetof(NamedPackageValueDataStorageLayout,b)==0,"public union overlap");
static_assert(offsetof(NamedPackageValueDataStorageLayout,i)==0,"public union overlap");
static_assert(offsetof(NamedPackageValueDataStorageLayout,f)==0,"public union overlap");
static_assert(offsetof(NamedPackageValueDataStorageLayout,p)==0,"public union overlap");
}
