// Source exposure: mixed (pinned public data declarations and independent target RTTI/secondary slot/target binding).
// Code origin: public data-only storage adaptations and original narrowed prefix composition. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BSTArray.h,B/BSTEvent.h,B/BSAtomic.h,B/BSNavmesh.h,B/BSResourceNiBinaryStream.h,E/ExtraMagicCaster.h,I/IAIWorldLocationHandle.h,I/IPackageData.h,I/IPackageDataAIWorldLocationHandle.h,M/MagicCaster.h,M/MenuControls.h,M/Main.h,N/NavMesh.h,N/NiBinaryStream.h,P/PlayerInputHandler.h,T/TES.h,T/TESCameraState.h,S/SimpleAnimationGraphManagerHolder.h}; MIT.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/{B/BSTask.h,I/IOTask.h,Q/QueuedFile.h,B/BSResourceEntryDB.h,B/BSTObjectDictionary.h,B/BSPathing.h,P/Pathing.h,F/FindTriangleForLocationFilterCheckDeltaZ.h}; GPL-3.0.
// QueuedFile, BSTask, IOTask, PostFlushNotify, BSTObjectDictionary, BSPathing, BSPathingCellManager, FindTriangleForLocationFilterCheckDeltaZ: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// MagicCaster, SimpleAnimationGraphManagerHolder, TESCameraState, PlayerInputHandler, BSTEventSource, BSTEventSink, ICellAttachDetachEventSource, BSNavmesh, TESChildCell, BSResourceNiBinaryStream, NiBinaryStream, IPackageData, IAIWorldLocationHandle, IPackageDataAIWorldLocationHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// New storage classes and contract names, identity tags, mirror fields and pointee names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "../forms/RaceComponentLayout.h"
#include "../represented_storage/BSExtraDataLayout.h"
#include "../represented_storage/LayoutValueTypes.h"
#include "../represented_storage/BSSoundHandleLayout.h"
#include "BSIntrusiveRefCountedStorageLayout.h"
namespace ResearchLayouts {
class QueuedParentPointeeLayout;
class MagicItemPointeeLayout;
class CameraPointeeLayout;
class GraphManagerPointeeLayout;
class GraphTaskPointeeLayout;
class ResourceStreamPointeeLayout;
class ResourceBufferPointeeLayout;
template<unsigned Identity> class RemainingVptrContractLayout { public: virtual ~RemainingVptrContractLayout(); };
class QueuedTaskDataStorageLayout {
public:
    virtual ~QueuedTaskDataStorageLayout();
    volatile std::int32_t refCount;
    std::uint32_t unk0C;
    std::uint64_t unk10;
};
class QueuedFileDataStorageLayout : public QueuedTaskDataStorageLayout {
public:
    ~QueuedFileDataStorageLayout() override;
    std::uint64_t unk18;
    QueuedParentPointeeLayout* parent;
    std::uint64_t children;
    std::uint64_t unk30;
};
class PostFlushNotifyDataStorageLayout {
public:
    virtual ~PostFlushNotifyDataStorageLayout();
    std::uint32_t state;
    PostFlushNotifyDataStorageLayout* next;
};
enum class MagicCasterStateStorageLayout : std::uint32_t {};
class MagicCasterDataStorageLayout {
public:
    virtual ~MagicCasterDataStorageLayout();
    BSTArray<BSSoundHandleLayout> sounds;
    ObjectRefHandle desiredTarget;
    MagicItemPointeeLayout* currentSpell;
    MagicCasterStateStorageLayout state;
    float castingTimer,currentSpellCost,magnitudeOverride,nextTargetUpdate,projectileTimer;
};
class SimpleGraphDataStorageLayout {
public:
    virtual ~SimpleGraphDataStorageLayout();
    GraphManagerPointeeLayout* animationGraphManager;
    GraphTaskPointeeLayout* loadingTask;
};
enum class CameraStateIdStorageLayout : std::uint32_t {};
class CameraStateDataStorageLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~CameraStateDataStorageLayout();
    CameraPointeeLayout* camera;
    CameraStateIdStorageLayout id;
};
class PlayerInputDataStorageLayout {
public:
    virtual ~PlayerInputDataStorageLayout();
    bool inputEventHandlingEnabled;
};
class NavmeshReferenceDataPrefixLayout : public BSIntrusiveRefCountedStorageLayout { public: virtual ~NavmeshReferenceDataPrefixLayout(); };
struct EventSpinLockDataStorageLayout { volatile std::uint32_t owningThread,lockCount; };
struct EventSourceDataStorageLayout {
    BSTArray<void*> sinks,pendingRegisters,pendingUnregisters;
    EventSpinLockDataStorageLayout lock;
    bool notifying;
};
class CellEventSourceDataStorageLayout {
public:
    virtual ~CellEventSourceDataStorageLayout();
    EventSourceDataStorageLayout events;
};
class BinaryStreamDataStorageLayout {
public:
    using ReadFn=std::uint32_t(BinaryStreamDataStorageLayout*,void*,std::uint32_t,std::uint32_t*,std::uint32_t);
    using WriteFn=std::uint32_t(BinaryStreamDataStorageLayout*,const void*,std::uint32_t,std::uint32_t*,std::uint32_t);
    virtual ~BinaryStreamDataStorageLayout();
    std::uint32_t absoluteCurrentPos;
    ReadFn* readFn;
    WriteFn* writeFn;
};
enum class ResourceStreamErrorStorageLayout : std::uint32_t {};
class ResourceBinaryDataStorageLayout : public BinaryStreamDataStorageLayout {
public:
    ~ResourceBinaryDataStorageLayout() override;
    ResourceStreamPointeeLayout* stream;
    ResourceBufferPointeeLayout* buffer;
    std::uint32_t streamPos;
    ResourceStreamErrorStorageLayout lastError;
};
class TriangleDeltaFilterDataStorageLayout {
public:
    virtual ~TriangleDeltaFilterDataStorageLayout();
    float maxDistAbove,maxDistBelow;
};
class PathingDataStorageLayout {
public:
    virtual ~PathingDataStorageLayout();
    TriangleDeltaFilterDataStorageLayout defaultTriangleFilter;
};
class PathingCellManagerContractLayout {
public:
    virtual void Slot00(); virtual void Slot01(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04();
    virtual void Slot05(); virtual void Slot06(); virtual void Slot07(); virtual void Slot08(); virtual void Slot09();
    virtual ~PathingCellManagerContractLayout();
};
static_assert(sizeof(QueuedTaskDataStorageLayout)==24,"represented public storage extent");
static_assert(sizeof(QueuedFileDataStorageLayout)==56,"represented public storage extent");
static_assert(sizeof(PostFlushNotifyDataStorageLayout)==24,"represented public storage extent");
static_assert(sizeof(MagicCasterDataStorageLayout)==72,"represented public storage extent");
static_assert(sizeof(SimpleGraphDataStorageLayout)==24,"represented public storage extent");
static_assert(sizeof(CameraStateDataStorageLayout)==32,"represented public storage extent");
static_assert(sizeof(PlayerInputDataStorageLayout)==16,"represented public storage extent");
static_assert(sizeof(NavmeshReferenceDataPrefixLayout)==16,"represented public storage extent");
static_assert(sizeof(EventSpinLockDataStorageLayout)==8,"represented public storage extent");
static_assert(sizeof(EventSourceDataStorageLayout)==88,"represented public storage extent");
static_assert(sizeof(CellEventSourceDataStorageLayout)==96,"represented public storage extent");
static_assert(sizeof(BinaryStreamDataStorageLayout)==32,"represented public storage extent");
static_assert(sizeof(ResourceBinaryDataStorageLayout)==56,"represented public storage extent");
static_assert(sizeof(TriangleDeltaFilterDataStorageLayout)==16,"represented public storage extent");
static_assert(sizeof(PathingDataStorageLayout)==24,"represented public storage extent");
static_assert(sizeof(PathingCellManagerContractLayout)==8,"represented public storage extent");
static_assert(offsetof(QueuedTaskDataStorageLayout,refCount)==8,"public field offset");
static_assert(offsetof(QueuedTaskDataStorageLayout,unk0C)==12,"public field offset");
static_assert(offsetof(QueuedTaskDataStorageLayout,unk10)==16,"public field offset");
static_assert(offsetof(QueuedFileDataStorageLayout,unk18)==24,"public field offset");
static_assert(offsetof(QueuedFileDataStorageLayout,parent)==32,"public field offset");
static_assert(offsetof(QueuedFileDataStorageLayout,children)==40,"public field offset");
static_assert(offsetof(QueuedFileDataStorageLayout,unk30)==48,"public field offset");
static_assert(offsetof(PostFlushNotifyDataStorageLayout,state)==8,"public field offset");
static_assert(offsetof(PostFlushNotifyDataStorageLayout,next)==16,"public field offset");
static_assert(offsetof(MagicCasterDataStorageLayout,sounds)==8,"public field offset");
static_assert(offsetof(MagicCasterDataStorageLayout,desiredTarget)==32,"public field offset");
static_assert(offsetof(MagicCasterDataStorageLayout,currentSpell)==40,"public field offset");
static_assert(offsetof(MagicCasterDataStorageLayout,state)==48,"public field offset");
static_assert(offsetof(MagicCasterDataStorageLayout,castingTimer)==52,"public field offset");
static_assert(offsetof(MagicCasterDataStorageLayout,currentSpellCost)==56,"public field offset");
static_assert(offsetof(MagicCasterDataStorageLayout,magnitudeOverride)==60,"public field offset");
static_assert(offsetof(MagicCasterDataStorageLayout,nextTargetUpdate)==64,"public field offset");
static_assert(offsetof(MagicCasterDataStorageLayout,projectileTimer)==68,"public field offset");
static_assert(offsetof(SimpleGraphDataStorageLayout,animationGraphManager)==8,"public field offset");
static_assert(offsetof(SimpleGraphDataStorageLayout,loadingTask)==16,"public field offset");
static_assert(offsetof(CameraStateDataStorageLayout,_refCount)==8,"public field offset");
static_assert(offsetof(CameraStateDataStorageLayout,camera)==16,"public field offset");
static_assert(offsetof(CameraStateDataStorageLayout,id)==24,"public field offset");
static_assert(offsetof(PlayerInputDataStorageLayout,inputEventHandlingEnabled)==8,"public field offset");
static_assert(offsetof(NavmeshReferenceDataPrefixLayout,_refCount)==8,"public field offset");
static_assert(offsetof(EventSpinLockDataStorageLayout,owningThread)==0,"public field offset");
static_assert(offsetof(EventSpinLockDataStorageLayout,lockCount)==4,"public field offset");
static_assert(offsetof(EventSourceDataStorageLayout,sinks)==0,"public field offset");
static_assert(offsetof(EventSourceDataStorageLayout,pendingRegisters)==24,"public field offset");
static_assert(offsetof(EventSourceDataStorageLayout,pendingUnregisters)==48,"public field offset");
static_assert(offsetof(EventSourceDataStorageLayout,lock)==72,"public field offset");
static_assert(offsetof(EventSourceDataStorageLayout,notifying)==80,"public field offset");
static_assert(offsetof(CellEventSourceDataStorageLayout,events)==8,"public field offset");
static_assert(offsetof(BinaryStreamDataStorageLayout,absoluteCurrentPos)==8,"public field offset");
static_assert(offsetof(BinaryStreamDataStorageLayout,readFn)==16,"public field offset");
static_assert(offsetof(BinaryStreamDataStorageLayout,writeFn)==24,"public field offset");
static_assert(offsetof(ResourceBinaryDataStorageLayout,stream)==32,"public field offset");
static_assert(offsetof(ResourceBinaryDataStorageLayout,buffer)==40,"public field offset");
static_assert(offsetof(ResourceBinaryDataStorageLayout,streamPos)==48,"public field offset");
static_assert(offsetof(ResourceBinaryDataStorageLayout,lastError)==52,"public field offset");
static_assert(offsetof(TriangleDeltaFilterDataStorageLayout,maxDistAbove)==8,"public field offset");
static_assert(offsetof(TriangleDeltaFilterDataStorageLayout,maxDistBelow)==12,"public field offset");
static_assert(offsetof(PathingDataStorageLayout,defaultTriangleFilter)==8,"public field offset");
static_assert(sizeof(RemainingVptrContractLayout<0>)==8,"represented initial vptr only");
// ActorMagicCaster: EXE_RTTI
// .?AVActorMagicCaster@@; initial prefix only.
class RemainingOwner18f6150PrefixLayout : public MagicCasterDataStorageLayout, public SimpleGraphDataStorageLayout, public RemainingVptrContractLayout<7000> {
public:
    RemainingOwner18f6150PrefixLayout();
    ~RemainingOwner18f6150PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18f6150PrefixLayout)==104,"initial owner prefix only");
struct RemainingOwner18f6150PrefixLayoutMirror {
    MagicCasterDataStorageLayout component0;
    SimpleGraphDataStorageLayout component1;
    RemainingVptrContractLayout<7000> component2;
};
static_assert(sizeof(RemainingOwner18f6150PrefixLayoutMirror)==104,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18f6150PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18f6150PrefixLayoutMirror,component1)==72,"independent target subobject start");
static_assert(offsetof(RemainingOwner18f6150PrefixLayoutMirror,component2)==96,"independent target subobject start");
// BGSNamedPackageData<VIAITarget@@>: EXE_RTTI
// .?AV?$BGSNamedPackageData@VIAITarget@@@@; initial prefix only.
class RemainingOwner18c4ab0PrefixLayout : public RemainingVptrContractLayout<7001>, public RemainingVptrContractLayout<7002> {
public:
    RemainingOwner18c4ab0PrefixLayout();
    ~RemainingOwner18c4ab0PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18c4ab0PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner18c4ab0PrefixLayoutMirror {
    RemainingVptrContractLayout<7001> component0;
    RemainingVptrContractLayout<7002> component1;
};
static_assert(sizeof(RemainingOwner18c4ab0PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18c4ab0PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18c4ab0PrefixLayoutMirror,component1)==8,"independent target subobject start");
// BGSNamedPackageData<VIPackageDataAIWorldLocationHandle@@>: EXE_RTTI
// .?AV?$BGSNamedPackageData@VIPackageDataAIWorldLocationHandle@@@@; initial prefix only.
class RemainingOwner18c4d48PrefixLayout : public RemainingVptrContractLayout<7003>, public RemainingVptrContractLayout<7004> {
public:
    RemainingOwner18c4d48PrefixLayout();
    ~RemainingOwner18c4d48PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18c4d48PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner18c4d48PrefixLayoutMirror {
    RemainingVptrContractLayout<7003> component0;
    RemainingVptrContractLayout<7004> component1;
};
static_assert(sizeof(RemainingOwner18c4d48PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18c4d48PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18c4d48PrefixLayoutMirror,component1)==8,"independent target subobject start");
// BGSPackageDataLocation: EXE_RTTI
// .?AVBGSPackageDataLocation@@; initial prefix only.
class RemainingOwner18c4e80PrefixLayout : public RemainingVptrContractLayout<7005>, public RemainingVptrContractLayout<7006> {
public:
    RemainingOwner18c4e80PrefixLayout();
    ~RemainingOwner18c4e80PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18c4e80PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner18c4e80PrefixLayoutMirror {
    RemainingVptrContractLayout<7005> component0;
    RemainingVptrContractLayout<7006> component1;
};
static_assert(sizeof(RemainingOwner18c4e80PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18c4e80PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18c4e80PrefixLayoutMirror,component1)==8,"independent target subobject start");
// BGSPackageDataObjectList: EXE_RTTI
// .?AVBGSPackageDataObjectList@@; initial prefix only.
class RemainingOwner18c5718PrefixLayout : public RemainingVptrContractLayout<7007>, public RemainingVptrContractLayout<7008> {
public:
    RemainingOwner18c5718PrefixLayout();
    ~RemainingOwner18c5718PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18c5718PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner18c5718PrefixLayoutMirror {
    RemainingVptrContractLayout<7007> component0;
    RemainingVptrContractLayout<7008> component1;
};
static_assert(sizeof(RemainingOwner18c5718PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18c5718PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18c5718PrefixLayoutMirror,component1)==8,"independent target subobject start");
// BGSPackageDataPointerTemplate<VIAITarget@@VPackageTarget@@$1?kPackageDataRef2TypeName@@3VBSFixedString@@B>: EXE_RTTI
// .?AV?$BGSPackageDataPointerTemplate@VIAITarget@@VPackageTarget@@$1?kPackageDataRef2TypeName@@3VBSFixedString@@B@@; initial prefix only.
class RemainingOwner18c5d00PrefixLayout : public RemainingVptrContractLayout<7009>, public RemainingVptrContractLayout<7010> {
public:
    RemainingOwner18c5d00PrefixLayout();
    ~RemainingOwner18c5d00PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18c5d00PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner18c5d00PrefixLayoutMirror {
    RemainingVptrContractLayout<7009> component0;
    RemainingVptrContractLayout<7010> component1;
};
static_assert(sizeof(RemainingOwner18c5d00PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18c5d00PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18c5d00PrefixLayoutMirror,component1)==8,"independent target subobject start");
// BGSPackageDataPointerTemplate<VIPackageDataAIWorldLocationHandle@@VPackageLocation@@$1?kPackageDataLocationTypeName@@3VBSFixedString@@B>: EXE_RTTI
// .?AV?$BGSPackageDataPointerTemplate@VIPackageDataAIWorldLocationHandle@@VPackageLocation@@$1?kPackageDataLocationTypeName@@3VBSFixedString@@B@@; initial prefix only.
class RemainingOwner18c4de0PrefixLayout : public RemainingVptrContractLayout<7011>, public RemainingVptrContractLayout<7012> {
public:
    RemainingOwner18c4de0PrefixLayout();
    ~RemainingOwner18c4de0PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18c4de0PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner18c4de0PrefixLayoutMirror {
    RemainingVptrContractLayout<7011> component0;
    RemainingVptrContractLayout<7012> component1;
};
static_assert(sizeof(RemainingOwner18c4de0PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18c4de0PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18c4de0PrefixLayoutMirror,component1)==8,"independent target subobject start");
// BGSPackageDataRef: EXE_RTTI
// .?AVBGSPackageDataRef@@; initial prefix only.
class RemainingOwner18c5de0PrefixLayout : public RemainingVptrContractLayout<7013>, public RemainingVptrContractLayout<7014> {
public:
    RemainingOwner18c5de0PrefixLayout();
    ~RemainingOwner18c5de0PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18c5de0PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner18c5de0PrefixLayoutMirror {
    RemainingVptrContractLayout<7013> component0;
    RemainingVptrContractLayout<7014> component1;
};
static_assert(sizeof(RemainingOwner18c5de0PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18c5de0PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18c5de0PrefixLayoutMirror,component1)==8,"independent target subobject start");
// BSModelDB::QueuedHandles: EXE_RTTI
// .?AVQueuedHandles@BSModelDB@@; initial prefix only.
class RemainingOwner17e2d08PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner17e2d08PrefixLayout();
    ~RemainingOwner17e2d08PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner17e2d08PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner17e2d08PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner17e2d08PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner17e2d08PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner17e2d08PrefixLayoutMirror,component1)==56,"independent target subobject start");
// BSQueuedResourceCollection<V?$EntryDB@UDBTraits@BSModelDB@@@BSResource@@$00>: EXE_RTTI
// .?AV?$BSQueuedResourceCollection@V?$EntryDB@UDBTraits@BSModelDB@@@BSResource@@$00@@; initial prefix only.
class RemainingOwner180b9f8PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner180b9f8PrefixLayout();
    ~RemainingOwner180b9f8PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner180b9f8PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner180b9f8PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner180b9f8PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner180b9f8PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner180b9f8PrefixLayoutMirror,component1)==56,"independent target subobject start");
// BSQueuedResourceCollection<V?$EntryDB@UDBTraits@BSModelDB@@@BSResource@@$01>: EXE_RTTI
// .?AV?$BSQueuedResourceCollection@V?$EntryDB@UDBTraits@BSModelDB@@@BSResource@@$01@@; initial prefix only.
class RemainingOwner17e2c48PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner17e2c48PrefixLayout();
    ~RemainingOwner17e2c48PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner17e2c48PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner17e2c48PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner17e2c48PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner17e2c48PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner17e2c48PrefixLayoutMirror,component1)==56,"independent target subobject start");
// BSQueuedResourceCollection<V?$EntryDB@UDBTraits@BSModelDB@@@BSResource@@$0CK@>: EXE_RTTI
// .?AV?$BSQueuedResourceCollection@V?$EntryDB@UDBTraits@BSModelDB@@@BSResource@@$0CK@@@; initial prefix only.
class RemainingOwner17ef048PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner17ef048PrefixLayout();
    ~RemainingOwner17ef048PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner17ef048PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner17ef048PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner17ef048PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner17ef048PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner17ef048PrefixLayoutMirror,component1)==56,"independent target subobject start");
// BSQueuedResourceCollection<V?$EntryDB@UDBTraits@BSTextureDB@@@BSResource@@$01>: EXE_RTTI
// .?AV?$BSQueuedResourceCollection@V?$EntryDB@UDBTraits@BSTextureDB@@@BSResource@@$01@@; initial prefix only.
class RemainingOwner1a6b088PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner1a6b088PrefixLayout();
    ~RemainingOwner1a6b088PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner1a6b088PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner1a6b088PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner1a6b088PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner1a6b088PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner1a6b088PrefixLayoutMirror,component1)==56,"independent target subobject start");
// BSQueuedResourceCollection<V?$EntryDB@UDBTraits@BShkbHkxDB@@@BSResource@@$01>: EXE_RTTI
// .?AV?$BSQueuedResourceCollection@V?$EntryDB@UDBTraits@BShkbHkxDB@@@BSResource@@$01@@; initial prefix only.
class RemainingOwner1a060a8PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner1a060a8PrefixLayout();
    ~RemainingOwner1a060a8PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner1a060a8PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner1a060a8PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner1a060a8PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner1a060a8PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner1a060a8PrefixLayoutMirror,component1)==56,"independent target subobject start");
// BSQueuedResourceCollection<V?$EntryDB@UDBTraits@TRI@BSFaceGenDB@@@BSResource@@$01>: EXE_RTTI
// .?AV?$BSQueuedResourceCollection@V?$EntryDB@UDBTraits@TRI@BSFaceGenDB@@@BSResource@@$01@@; initial prefix only.
class RemainingOwner18bf698PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner18bf698PrefixLayout();
    ~RemainingOwner18bf698PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18bf698PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner18bf698PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner18bf698PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18bf698PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18bf698PrefixLayoutMirror,component1)==56,"independent target subobject start");
// BSResourceStreamParser: EXE_RTTI
// .?AVBSResourceStreamParser@@; initial prefix only.
class RemainingOwner1a9aaa8PrefixLayout : public ResourceBinaryDataStorageLayout, public RemainingVptrContractLayout<7015> {
public:
    RemainingOwner1a9aaa8PrefixLayout();
    ~RemainingOwner1a9aaa8PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner1a9aaa8PrefixLayout)==64,"initial owner prefix only");
struct RemainingOwner1a9aaa8PrefixLayoutMirror {
    ResourceBinaryDataStorageLayout component0;
    RemainingVptrContractLayout<7015> component1;
};
static_assert(sizeof(RemainingOwner1a9aaa8PrefixLayoutMirror)==64,"physical prefix mirror");
static_assert(offsetof(RemainingOwner1a9aaa8PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner1a9aaa8PrefixLayoutMirror,component1)==56,"independent target subobject start");
// BSTObjectDictionary<V?$BSTSmartPointer@V?$BSResponse@VBSFixedStringCI@@VActor@@V1@VDoNothingUnhandledPolicy@@@@UBSTSmartPointerIntrusiveRefCount@@@@VBSFixedStringCI@@VResponseDefinitionMissPolicy@@VPreloadResponsesInitializationPolicy@@>: EXE_RTTI
// .?AV?$BSTObjectDictionary@V?$BSTSmartPointer@V?$BSResponse@VBSFixedStringCI@@VActor@@V1@VDoNothingUnhandledPolicy@@@@UBSTSmartPointerIntrusiveRefCount@@@@VBSFixedStringCI@@VResponseDefinitionMissPolicy@@VPreloadResponsesInitializationPolicy@@@@; initial prefix only.
class RemainingOwner193ba10PrefixLayout : public RemainingVptrContractLayout<7016>, public RemainingVptrContractLayout<7017> {
public:
    RemainingOwner193ba10PrefixLayout();
    ~RemainingOwner193ba10PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner193ba10PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner193ba10PrefixLayoutMirror {
    RemainingVptrContractLayout<7016> component0;
    RemainingVptrContractLayout<7017> component1;
};
static_assert(sizeof(RemainingOwner193ba10PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner193ba10PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner193ba10PrefixLayoutMirror,component1)==8,"independent target subobject start");
// BSTObjectDictionary<V?$BSTSmartPointer@V?$IHandlerFunctor@VActor@@VBSFixedStringCI@@@@UBSTSmartPointerIntrusiveRefCount@@@@VBSFixedStringCI@@VHandlerCreationMissPolicy@@VNoInitializationPolicy@@>: EXE_RTTI
// .?AV?$BSTObjectDictionary@V?$BSTSmartPointer@V?$IHandlerFunctor@VActor@@VBSFixedStringCI@@@@UBSTSmartPointerIntrusiveRefCount@@@@VBSFixedStringCI@@VHandlerCreationMissPolicy@@VNoInitializationPolicy@@@@; initial prefix only.
class RemainingOwner193b9d0PrefixLayout : public RemainingVptrContractLayout<7018>, public RemainingVptrContractLayout<7019> {
public:
    RemainingOwner193b9d0PrefixLayout();
    ~RemainingOwner193b9d0PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner193b9d0PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner193b9d0PrefixLayoutMirror {
    RemainingVptrContractLayout<7018> component0;
    RemainingVptrContractLayout<7019> component1;
};
static_assert(sizeof(RemainingOwner193b9d0PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner193b9d0PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner193b9d0PrefixLayoutMirror,component1)==8,"independent target subobject start");
// FirstPersonState: EXE_RTTI
// .?AVFirstPersonState@@; initial prefix only.
class RemainingOwner196d8f0PrefixLayout : public CameraStateDataStorageLayout, public PlayerInputDataStorageLayout {
public:
    RemainingOwner196d8f0PrefixLayout();
    ~RemainingOwner196d8f0PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner196d8f0PrefixLayout)==48,"initial owner prefix only");
struct RemainingOwner196d8f0PrefixLayoutMirror {
    CameraStateDataStorageLayout component0;
    PlayerInputDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner196d8f0PrefixLayoutMirror)==48,"physical prefix mirror");
static_assert(offsetof(RemainingOwner196d8f0PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner196d8f0PrefixLayoutMirror,component1)==32,"independent target subobject start");
// FreeCameraState: EXE_RTTI
// .?AVFreeCameraState@@; initial prefix only.
class RemainingOwner196d9f0PrefixLayout : public CameraStateDataStorageLayout, public PlayerInputDataStorageLayout {
public:
    RemainingOwner196d9f0PrefixLayout();
    ~RemainingOwner196d9f0PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner196d9f0PrefixLayout)==48,"initial owner prefix only");
struct RemainingOwner196d9f0PrefixLayoutMirror {
    CameraStateDataStorageLayout component0;
    PlayerInputDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner196d9f0PrefixLayoutMirror)==48,"physical prefix mirror");
static_assert(offsetof(RemainingOwner196d9f0PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner196d9f0PrefixLayoutMirror,component1)==32,"independent target subobject start");
// Main: EXE_RTTI
// .?AVMain@@; initial prefix only.
class RemainingOwner1914158PrefixLayout : public RemainingVptrContractLayout<7020>, public RemainingVptrContractLayout<7021> {
public:
    RemainingOwner1914158PrefixLayout();
    ~RemainingOwner1914158PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner1914158PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner1914158PrefixLayoutMirror {
    RemainingVptrContractLayout<7020> component0;
    RemainingVptrContractLayout<7021> component1;
};
static_assert(sizeof(RemainingOwner1914158PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner1914158PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner1914158PrefixLayoutMirror,component1)==8,"independent target subobject start");
// MenuControls: EXE_RTTI
// .?AVMenuControls@@; initial prefix only.
class RemainingOwner197c1e8PrefixLayout : public RemainingVptrContractLayout<7022>, public RemainingVptrContractLayout<7023> {
public:
    RemainingOwner197c1e8PrefixLayout();
    ~RemainingOwner197c1e8PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner197c1e8PrefixLayout)==16,"initial owner prefix only");
struct RemainingOwner197c1e8PrefixLayoutMirror {
    RemainingVptrContractLayout<7022> component0;
    RemainingVptrContractLayout<7023> component1;
};
static_assert(sizeof(RemainingOwner197c1e8PrefixLayoutMirror)==16,"physical prefix mirror");
static_assert(offsetof(RemainingOwner197c1e8PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner197c1e8PrefixLayoutMirror,component1)==8,"independent target subobject start");
// NavMesh: EXE_RTTI
// .?AVNavMesh@@; initial prefix only.
class RemainingOwner18d9388PrefixLayout : public FormHeaderLayout, public RemainingVptrContractLayout<7024>, public NavmeshReferenceDataPrefixLayout {
public:
    RemainingOwner18d9388PrefixLayout();
    ~RemainingOwner18d9388PrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(RemainingOwner18d9388PrefixLayout)==56,"initial owner prefix only");
struct RemainingOwner18d9388PrefixLayoutMirror {
    FormHeaderLayout component0;
    RemainingVptrContractLayout<7024> component1;
    NavmeshReferenceDataPrefixLayout component2;
};
static_assert(sizeof(RemainingOwner18d9388PrefixLayoutMirror)==56,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18d9388PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18d9388PrefixLayoutMirror,component1)==32,"independent target subobject start");
static_assert(offsetof(RemainingOwner18d9388PrefixLayoutMirror,component2)==40,"independent target subobject start");
// NonActorMagicCaster: EXE_RTTI
// .?AVNonActorMagicCaster@@; initial prefix only.
class RemainingOwner18f9ce0PrefixLayout : public BSExtraDataLayout, public MagicCasterDataStorageLayout {
public:
    RemainingOwner18f9ce0PrefixLayout();
    ~RemainingOwner18f9ce0PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18f9ce0PrefixLayout)==88,"initial owner prefix only");
struct RemainingOwner18f9ce0PrefixLayoutMirror {
    BSExtraDataLayout component0;
    MagicCasterDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner18f9ce0PrefixLayoutMirror)==88,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18f9ce0PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18f9ce0PrefixLayoutMirror,component1)==16,"independent target subobject start");
// Pathing: EXE_RTTI
// .?AVPathing@@; initial prefix only.
class RemainingOwner18dcdd0PrefixLayout : public PathingDataStorageLayout, public PathingCellManagerContractLayout, public RemainingVptrContractLayout<7025> {
public:
    RemainingOwner18dcdd0PrefixLayout();
    ~RemainingOwner18dcdd0PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner18dcdd0PrefixLayout)==40,"initial owner prefix only");
struct RemainingOwner18dcdd0PrefixLayoutMirror {
    PathingDataStorageLayout component0;
    PathingCellManagerContractLayout component1;
    RemainingVptrContractLayout<7025> component2;
};
static_assert(sizeof(RemainingOwner18dcdd0PrefixLayoutMirror)==40,"physical prefix mirror");
static_assert(offsetof(RemainingOwner18dcdd0PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner18dcdd0PrefixLayoutMirror,component1)==24,"independent target subobject start");
static_assert(offsetof(RemainingOwner18dcdd0PrefixLayoutMirror,component2)==32,"independent target subobject start");
// QueuedActor: EXE_RTTI
// .?AVQueuedActor@@; initial prefix only.
class RemainingOwner17ef750PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner17ef750PrefixLayout();
    ~RemainingOwner17ef750PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner17ef750PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner17ef750PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner17ef750PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner17ef750PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner17ef750PrefixLayoutMirror,component1)==56,"independent target subobject start");
// QueuedCharacter: EXE_RTTI
// .?AVQueuedCharacter@@; initial prefix only.
class RemainingOwner17ef848PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner17ef848PrefixLayout();
    ~RemainingOwner17ef848PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner17ef848PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner17ef848PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner17ef848PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner17ef848PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner17ef848PrefixLayoutMirror,component1)==56,"independent target subobject start");
// QueuedPlayer: EXE_RTTI
// .?AVQueuedPlayer@@; initial prefix only.
class RemainingOwner17ef960PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner17ef960PrefixLayout();
    ~RemainingOwner17ef960PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner17ef960PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner17ef960PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner17ef960PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner17ef960PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner17ef960PrefixLayoutMirror,component1)==56,"independent target subobject start");
// QueuedReference: EXE_RTTI
// .?AVQueuedReference@@; initial prefix only.
class RemainingOwner17ef2e8PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner17ef2e8PrefixLayout();
    ~RemainingOwner17ef2e8PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner17ef2e8PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner17ef2e8PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner17ef2e8PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner17ef2e8PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner17ef2e8PrefixLayoutMirror,component1)==56,"independent target subobject start");
// QueuedTree: EXE_RTTI
// .?AVQueuedTree@@; initial prefix only.
class RemainingOwner17ef658PrefixLayout : public QueuedFileDataStorageLayout, public PostFlushNotifyDataStorageLayout {
public:
    RemainingOwner17ef658PrefixLayout();
    ~RemainingOwner17ef658PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner17ef658PrefixLayout)==80,"initial owner prefix only");
struct RemainingOwner17ef658PrefixLayoutMirror {
    QueuedFileDataStorageLayout component0;
    PostFlushNotifyDataStorageLayout component1;
};
static_assert(sizeof(RemainingOwner17ef658PrefixLayoutMirror)==80,"physical prefix mirror");
static_assert(offsetof(RemainingOwner17ef658PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner17ef658PrefixLayoutMirror,component1)==56,"independent target subobject start");
// TES: EXE_RTTI
// .?AVTES@@; initial prefix only.
class RemainingOwner17f3ea0PrefixLayout : public CellEventSourceDataStorageLayout, public RemainingVptrContractLayout<7026>, public RemainingVptrContractLayout<7027> {
public:
    RemainingOwner17f3ea0PrefixLayout();
    ~RemainingOwner17f3ea0PrefixLayout() override;
};
static_assert(sizeof(RemainingOwner17f3ea0PrefixLayout)==112,"initial owner prefix only");
struct RemainingOwner17f3ea0PrefixLayoutMirror {
    CellEventSourceDataStorageLayout component0;
    RemainingVptrContractLayout<7026> component1;
    RemainingVptrContractLayout<7027> component2;
};
static_assert(sizeof(RemainingOwner17f3ea0PrefixLayoutMirror)==112,"physical prefix mirror");
static_assert(offsetof(RemainingOwner17f3ea0PrefixLayoutMirror,component0)==0,"independent target subobject start");
static_assert(offsetof(RemainingOwner17f3ea0PrefixLayoutMirror,component1)==96,"independent target subobject start");
static_assert(offsetof(RemainingOwner17f3ea0PrefixLayoutMirror,component2)==104,"independent target subobject start");
}
