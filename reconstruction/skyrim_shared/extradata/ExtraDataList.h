// Source exposure: mixed (pinned target image, community headers).
// Code origin: adapted pinned community declarations and target-informed typed prefix stand-ins; no sibling body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; MIT.
// Prefix layout names and inferred members: GUESS(low) STANDIN
// Community type and member names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
namespace ResearchLayouts {
class BGSScene; class BGSLocation; class TESGlobal; class BGSAcousticSpace;
class REFR_LIGHT; class MapMarkerData; class REFR_LOCK; class BGSLocationRefType;
class TESObjectREFR; class TESObjectCELL; class EnableStateChildren; class BGSKeyword;
class TESFileArray; class TESBoundObject; class LOADED_REF_DATA; class BSExtraData;
struct PresenceBitfield;
enum class OBJECT_ACTION;
// Prefix stand-ins: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESForm {
public:
    virtual ~TESForm();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    TESFileArray* sourceFiles;
    std::uint32_t formFlags;
    std::uint32_t formID;
    std::uint16_t inGameFormFlags;
    std::uint8_t formType;
    std::uint8_t pad1B;
    std::uint32_t pad1C;
};
static_assert(sizeof(TESForm) == 0x20, "TESForm prefix");
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); volatile std::uint32_t refCount; std::uint32_t pad0C; };
class BSHandleRefObject : public NiRefObject {};
class BSAnimationGraphEventSink { public: virtual ~BSAnimationGraphEventSink(); };
class IAnimationGraphManagerHolder { public: virtual ~IAnimationGraphManagerHolder(); };
struct NiPoint3 { float x; float y; float z; };
struct OBJ_REFR { TESBoundObject* objectReference; NiPoint3 angle; NiPoint3 location; };
static_assert(sizeof(OBJ_REFR) == 0x20, "OBJ_REFR prefix");
struct BSFixedString { const char* data; };
class TESFullName { public: virtual ~TESFullName(); BSFixedString fullName; };
class BSSpinLock { public: volatile std::uint32_t owningThread; volatile std::uint32_t lockCount; };
class BSReadWriteLock { public: volatile std::uint32_t writerThread; volatile std::uint32_t lock; };
class BaseExtraList { public: virtual ~BaseExtraList(); BSExtraData* data; PresenceBitfield* presence; };
class ExtraDataList { public:
void ForceEditorLocation(BGSLocation*); BGSScene* GetCurrentScene() const; void SetCurrentScene(BGSScene*);
TESGlobal* GetGlobal() const;
unsigned int GetDetachTime() const;
BGSAcousticSpace* GetAcousticSpace() const;
REFR_LIGHT* GetMagicLightData() const;
OBJECT_ACTION GetAction() const;
bool HasAction(unsigned int flags) const;
TESObjectREFR* GetActionReference() const;
TESForm* GetOwner();
MapMarkerData* GetMapMarkerData() const;
REFR_LOCK* GetLock() const;
TESObjectREFR* GetMultiBoundRef() const;
BGSLocationRefType* GetLocationRefType() const;
TESForm* GetEmittanceSource() const;
TESObjectREFR* GetRandomTeleportMarker() const;
bool IsOppositeEnableState() const;
EnableStateChildren* GetEnableStateChildren() const;
TESObjectREFR* GetLinkedRef(BGSKeyword* keyword);
    BaseExtraList list;
    BSReadWriteLock lock;
    unsigned int Function1573b0() const;
    bool Function1573e0(unsigned int type) const;
};
static_assert(sizeof(BaseExtraList) == 0x18, "AE BaseExtraList representation");
static_assert(offsetof(ExtraDataList, lock) == 0x18, "observed list lock offset");
}
