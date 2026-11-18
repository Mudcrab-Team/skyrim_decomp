// Source exposure: mixed (community declarations, target RTTI bindings).
// CommunityLeafStorageLayout: GUESS(medium) STANDIN; represented public storage alias.
// Code origin: public data declarations and represented reference-count inheritance; no implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSIntrusiveRefCounted.h, BSTFreeList.h; S/SettingCollection.h, SimpleAllocMemoryPagePolicy.h; A/AttachLightHitEffectVisitor.h, ActorTargetCheck.h; F/FastTravelConfirmCallback.h; I/IFunction.h, IFuncCallQuery.h, IVirtualMachine.h, IMessageBoxCallback.h, IMemoryPagePolicy.h; D/DelayFunctor.h; B/BSAtomic.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// CommunityReferenceCount: GUESS(medium) STANDIN; public BSIntrusiveRefCounted layout alias.
// _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct CommunityReferenceCount { mutable volatile std::uint32_t _refCount; };
// CommunityRef2857c0: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef2857c0 : public CommunityReferenceCount { public: virtual ~CommunityRef2857c0();
};
static_assert(sizeof(CommunityRef2857c0)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef2857c0,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRef2feba0: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef2feba0 : public CommunityReferenceCount { public: virtual ~CommunityRef2feba0();
};
static_assert(sizeof(CommunityRef2feba0)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef2feba0,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRef4726a0: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef4726a0 : public CommunityReferenceCount { public: virtual ~CommunityRef4726a0();
};
static_assert(sizeof(CommunityRef4726a0)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef4726a0,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRef4e2000: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef4e2000 : public CommunityReferenceCount { public: virtual ~CommunityRef4e2000();
};
static_assert(sizeof(CommunityRef4e2000)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef4e2000,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRef4e2ce0: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef4e2ce0 : public CommunityReferenceCount { public: virtual ~CommunityRef4e2ce0();
};
static_assert(sizeof(CommunityRef4e2ce0)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef4e2ce0,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRef4e3a50: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef4e3a50 : public CommunityReferenceCount { public: virtual ~CommunityRef4e3a50();
};
static_assert(sizeof(CommunityRef4e3a50)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef4e3a50,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRef9b2a20: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef9b2a20 : public CommunityReferenceCount { public: virtual ~CommunityRef9b2a20();
// stackID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t stackID;
};
static_assert(sizeof(CommunityRef9b2a20)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef9b2a20,stackID)==12, "declared member offset");
static_assert(offsetof(CommunityRef9b2a20,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityReff22f30: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityReff22f30 : public CommunityReferenceCount { public: virtual ~CommunityReff22f30();
};
static_assert(sizeof(CommunityReff22f30)==16, "represented public fields and base");
static_assert(offsetof(CommunityReff22f30,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRef1497090: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef1497090 : public CommunityReferenceCount { public: virtual ~CommunityRef1497090();
};
static_assert(sizeof(CommunityRef1497090)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef1497090,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRef14aa3a0: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef14aa3a0 : public CommunityReferenceCount { public: virtual ~CommunityRef14aa3a0();
};
static_assert(sizeof(CommunityRef14aa3a0)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef14aa3a0,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRef14c8960: GUESS(medium) STANDIN; public reference-count inheritance; DelayFunctor stackID retained where present.
class CommunityRef14c8960 : public CommunityReferenceCount { public: virtual ~CommunityRef14c8960();
};
static_assert(sizeof(CommunityRef14c8960)==16, "represented public fields and base");
static_assert(offsetof(CommunityRef14c8960,_refCount)==8,"RTTI primary reference-count subobject");
// CommunityRefOwner9a7f60: GUESS(medium) STANDIN; primary callback inheritance observed by RTTI, no additional field asserted.
class CommunityRefOwner9a7f60 : public CommunityRef2857c0 { public: ~CommunityRefOwner9a7f60();
};
static_assert(sizeof(CommunityRefOwner9a7f60)==16, "represented public fields and base");
// CommunityRefOwnera2acb0: GUESS(medium) STANDIN; primary callback inheritance observed by RTTI, no additional field asserted.
class CommunityRefOwnera2acb0 : public CommunityRef2857c0 { public: ~CommunityRefOwnera2acb0();
};
static_assert(sizeof(CommunityRefOwnera2acb0)==16, "represented public fields and base");
// CommunityFreeEntry: GUESS(low) STANDIN; incomplete public free-list element pointee.
struct CommunityFreeEntry;
// CommunityFree6bc1a0: GUESS(medium) STANDIN; BSTFreeList.h declarations, template arguments unassessed.
class CommunityFree6bc1a0 { public: virtual ~CommunityFree6bc1a0();
// lock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t lock;
// free: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityFreeEntry* free;
};
static_assert(sizeof(CommunityFree6bc1a0)==24, "represented public fields and base");
static_assert(offsetof(CommunityFree6bc1a0,lock)==8, "declared member offset");
static_assert(offsetof(CommunityFree6bc1a0,free)==16, "declared member offset");
// CommunityFree9f0290: GUESS(medium) STANDIN; BSTFreeList.h declarations, template arguments unassessed.
class CommunityFree9f0290 { public: virtual ~CommunityFree9f0290();
// lock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t lock;
// free: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityFreeEntry* free;
};
static_assert(sizeof(CommunityFree9f0290)==24, "represented public fields and base");
static_assert(offsetof(CommunityFree9f0290,lock)==8, "declared member offset");
static_assert(offsetof(CommunityFree9f0290,free)==16, "declared member offset");
// CommunityFree14c8860: GUESS(medium) STANDIN; BSTFreeList.h declarations, template arguments unassessed.
class CommunityFree14c8860 { public: virtual ~CommunityFree14c8860();
// lock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t lock;
// free: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityFreeEntry* free;
};
static_assert(sizeof(CommunityFree14c8860)==24, "represented public fields and base");
static_assert(offsetof(CommunityFree14c8860,lock)==8, "declared member offset");
static_assert(offsetof(CommunityFree14c8860,free)==16, "declared member offset");
// CommunityLeafStorageLayout: GUESS(medium) STANDIN; SettingCollection.h public key and handle.
class CommunityLeafStorageLayout { public: virtual ~CommunityLeafStorageLayout();
// subKey: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
char subKey[260];
// handle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
void* handle;
};
static_assert(sizeof(CommunityLeafStorageLayout)==280, "represented public fields and base");
static_assert(offsetof(CommunityLeafStorageLayout,subKey)==8, "declared member offset");
static_assert(offsetof(CommunityLeafStorageLayout,handle)==272, "declared member offset");
// CommunityHitVisitor: GUESS(medium) STANDIN; AttachLightHitEffectVisitor.h public base.
class CommunityHitVisitor { public: virtual ~CommunityHitVisitor();
};
static_assert(sizeof(CommunityHitVisitor)==8, "represented public fields and base");
// CommunityHitOwner: GUESS(medium) STANDIN; AttachLightHitEffectVisitor.h public owner fields.
class CommunityHitOwner : public CommunityHitVisitor { public: ~CommunityHitOwner();
// attachRoot: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
void* attachRoot;
// attachLightNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
void* attachLightNode;
// allAttached: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
bool allAttached;
};
static_assert(sizeof(CommunityHitOwner)==32, "represented public fields and base");
static_assert(offsetof(CommunityHitOwner,attachRoot)==8, "declared member offset");
static_assert(offsetof(CommunityHitOwner,attachLightNode)==16, "declared member offset");
static_assert(offsetof(CommunityHitOwner,allAttached)==24, "declared member offset");
// CommunityActorFilter: GUESS(medium) STANDIN; ActorTargetCheck.h public base.
class CommunityActorFilter { public: virtual ~CommunityActorFilter();
};
static_assert(sizeof(CommunityActorFilter)==8, "represented public fields and base");
// CommunityActorTarget: GUESS(medium) STANDIN; ActorTargetCheck.h public owner fields.
class CommunityActorTarget : public CommunityActorFilter { public: ~CommunityActorTarget();
// unk08: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint64_t unk08;
// unk10: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint64_t unk10;
// unk18: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint64_t unk18;
};
static_assert(sizeof(CommunityActorTarget)==32, "represented public fields and base");
static_assert(offsetof(CommunityActorTarget,unk08)==8, "declared member offset");
static_assert(offsetof(CommunityActorTarget,unk10)==16, "declared member offset");
static_assert(offsetof(CommunityActorTarget,unk18)==24, "declared member offset");
// CommunityMessageCallback: GUESS(medium) STANDIN; FastTravelConfirmCallback.h and IMessageBoxCallback.h public base.
class CommunityMessageCallback : public CommunityReferenceCount { public: virtual ~CommunityMessageCallback();
// unk0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t unk0C;
};
static_assert(sizeof(CommunityMessageCallback)==16, "represented public fields and base");
static_assert(offsetof(CommunityMessageCallback,unk0C)==12, "declared member offset");
// CommunityFastTravel: GUESS(medium) STANDIN; FastTravelConfirmCallback.h and IMessageBoxCallback.h public owner fields.
class CommunityFastTravel : public CommunityMessageCallback { public: ~CommunityFastTravel();
// mapMenu: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
void* mapMenu;
// cursorPosX: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::int32_t cursorPosX;
// cursorPosY: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::int32_t cursorPosY;
};
static_assert(sizeof(CommunityFastTravel)==32, "represented public fields and base");
static_assert(offsetof(CommunityFastTravel,mapMenu)==16, "declared member offset");
static_assert(offsetof(CommunityFastTravel,cursorPosX)==24, "declared member offset");
static_assert(offsetof(CommunityFastTravel,cursorPosY)==28, "declared member offset");
// CommunityPagePolicy: GUESS(medium) STANDIN; SimpleAllocMemoryPagePolicy.h, IMemoryPagePolicy.h, BSAtomic.h public base.
class CommunityPagePolicy { public: virtual ~CommunityPagePolicy();
};
static_assert(sizeof(CommunityPagePolicy)==8, "represented public fields and base");
// CommunitySimplePage: GUESS(medium) STANDIN; SimpleAllocMemoryPagePolicy.h, IMemoryPagePolicy.h, BSAtomic.h public owner fields.
class CommunitySimplePage : public CommunityPagePolicy { public: ~CommunitySimplePage();
// minPageSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t minPageSize;
// maxPageSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t maxPageSize;
// maxAllocatedMemory: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t maxAllocatedMemory;
// ignoreMemoryLimit: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
bool ignoreMemoryLimit;
// owningThread: GUESS(medium) STANDIN; adapted from the public BSSpinLock member with leading underscore.
std::uint32_t owningThread;
// lockCount: GUESS(medium) STANDIN; adapted from the public BSSpinLock member with leading underscore.
volatile std::uint32_t lockCount;
// currentMemorySize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t currentMemorySize;
// maxAdditionalAllocations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint32_t maxAdditionalAllocations;
};
static_assert(sizeof(CommunitySimplePage)==40, "represented public fields and base");
static_assert(offsetof(CommunitySimplePage,minPageSize)==8, "declared member offset");
static_assert(offsetof(CommunitySimplePage,maxPageSize)==12, "declared member offset");
static_assert(offsetof(CommunitySimplePage,maxAllocatedMemory)==16, "declared member offset");
static_assert(offsetof(CommunitySimplePage,ignoreMemoryLimit)==20, "declared member offset");
static_assert(offsetof(CommunitySimplePage,owningThread)==24, "declared member offset");
static_assert(offsetof(CommunitySimplePage,lockCount)==28, "declared member offset");
static_assert(offsetof(CommunitySimplePage,currentMemorySize)==32, "declared member offset");
static_assert(offsetof(CommunitySimplePage,maxAdditionalAllocations)==36, "declared member offset");
}
