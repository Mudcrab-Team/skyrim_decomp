// Source exposure: mixed (community declarations and local target binding).
// Code origin: data declarations adapted from pinned public CommonLibSSE-NG headers. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSPointerHandle.h, BSTMessageQueue.h, BSExtraData.h; I/IUIMessageData.h, S/SyncQueueObj.h and the corresponding named handle-owner headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HandleExtraDeleteLayout, HandleUIRoot, HandleSyncRoot, HandleReferenceCount, HandleNativeValue: GUESS(medium) STANDIN; represented public data aliases.
// _handle, _refCount, next, unk08, unk0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
struct HandleNativeValue { std::uint32_t _handle; };
struct HandleReferenceCount { mutable volatile std::uint32_t _refCount; };
class HandleExtraDeleteLayout { public: virtual ~HandleExtraDeleteLayout(); HandleExtraDeleteLayout* next; };
class HandleUIRoot { public: virtual ~HandleUIRoot(); std::uint16_t unk08; };
class HandleSyncRoot : public HandleReferenceCount { public: virtual ~HandleSyncRoot(); std::uint32_t unk0C; };
static_assert(sizeof(HandleNativeValue)==4, "public native handle");
static_assert(sizeof(HandleExtraDeleteLayout)==16, "extra-data base");
static_assert(sizeof(HandleUIRoot)==16, "UI base");
static_assert(sizeof(HandleSyncRoot)==16, "sync base");
// HandleOwner17c280: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraAshPileRef.h.
class HandleOwner17c280 : public HandleExtraDeleteLayout { public: ~HandleOwner17c280() override;
// ashPileRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue ashPileRef;
};
static_assert(sizeof(HandleOwner17c280)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17c280,ashPileRef)==16, "public member offset");
// HandleOwner17c2b0: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraAttachRef.h.
class HandleOwner17c2b0 : public HandleExtraDeleteLayout { public: ~HandleOwner17c2b0() override;
// attachRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue attachRef;
};
static_assert(sizeof(HandleOwner17c2b0)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17c2b0,attachRef)==16, "public member offset");
// HandleOwner17c830: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraEnableStateParent.h.
class HandleOwner17c830 : public HandleExtraDeleteLayout { public: ~HandleOwner17c830() override;
// flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
std::int8_t flags;
// parent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue parent;
};
static_assert(sizeof(HandleOwner17c830)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17c830,flags)==16, "public member offset");
static_assert(offsetof(HandleOwner17c830,parent)==20, "public member offset");
// HandleOwner17ca20: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraForcedLandingMarker.h.
class HandleOwner17ca20 : public HandleExtraDeleteLayout { public: ~HandleOwner17ca20() override;
// landingMarker: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue landingMarker;
};
static_assert(sizeof(HandleOwner17ca20)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17ca20,landingMarker)==16, "public member offset");
// HandleOwner17ca50: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraForcedTarget.h.
class HandleOwner17ca50 : public HandleExtraDeleteLayout { public: ~HandleOwner17ca50() override;
// target: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue target;
};
static_assert(sizeof(HandleOwner17ca50)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17ca50,target)==16, "public member offset");
// HandleOwner17cca0: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraHeadingTarget.h.
class HandleOwner17cca0 : public HandleExtraDeleteLayout { public: ~HandleOwner17cca0() override;
// target: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue target;
};
static_assert(sizeof(HandleOwner17cca0)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17cca0,target)==16, "public member offset");
// HandleOwner17cd30: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraHorse.h.
class HandleOwner17cd30 : public HandleExtraDeleteLayout { public: ~HandleOwner17cd30() override;
// horseRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue horseRef;
};
static_assert(sizeof(HandleOwner17cd30)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17cd30,horseRef)==16, "public member offset");
// HandleOwner17cdc0: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraItemDropper.h.
class HandleOwner17cdc0 : public HandleExtraDeleteLayout { public: ~HandleOwner17cdc0() override;
// dropper: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue dropper;
};
static_assert(sizeof(HandleOwner17cdc0)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17cdc0,dropper)==16, "public member offset");
// HandleOwner17d420: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraOpenCloseActivateRef.h.
class HandleOwner17d420 : public HandleExtraDeleteLayout { public: ~HandleOwner17d420() override;
// activateRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue activateRef;
};
static_assert(sizeof(HandleOwner17d420)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17d420,activateRef)==16, "public member offset");
// HandleOwner17d450: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraOriginalReference.h.
class HandleOwner17d450 : public HandleExtraDeleteLayout { public: ~HandleOwner17d450() override;
// reference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue reference;
};
static_assert(sizeof(HandleOwner17d450)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17d450,reference)==16, "public member offset");
// HandleOwner18f610: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraPackage.h.
class HandleOwner18f610 : public HandleExtraDeleteLayout { public: ~HandleOwner18f610() override;
// unk10: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
void* unk10;
// index: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
std::int32_t index;
// target: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue target;
// actionComplete: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
bool actionComplete;
// activated: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
bool activated;
// doneOnce: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
bool doneOnce;
// unk23: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
std::uint8_t unk23;
// unk24: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
std::uint32_t unk24;
};
static_assert(sizeof(HandleOwner18f610)==40, "declared owner fields");
static_assert(offsetof(HandleOwner18f610,unk10)==16, "public member offset");
static_assert(offsetof(HandleOwner18f610,index)==24, "public member offset");
static_assert(offsetof(HandleOwner18f610,target)==28, "public member offset");
static_assert(offsetof(HandleOwner18f610,actionComplete)==32, "public member offset");
static_assert(offsetof(HandleOwner18f610,activated)==33, "public member offset");
static_assert(offsetof(HandleOwner18f610,doneOnce)==34, "public member offset");
static_assert(offsetof(HandleOwner18f610,unk23)==35, "public member offset");
static_assert(offsetof(HandleOwner18f610,unk24)==36, "public member offset");
// HandleOwner17d7c0: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraReferenceHandle.h.
class HandleOwner17d7c0 : public HandleExtraDeleteLayout { public: ~HandleOwner17d7c0() override;
// containerRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue containerRef;
};
static_assert(sizeof(HandleOwner17d7c0)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17d7c0,containerRef)==16, "public member offset");
// HandleOwner17dbc0: GUESS(medium) STANDIN; declarations adapt include/RE/E/ExtraSpawnContainer.h.
class HandleOwner17dbc0 : public HandleExtraDeleteLayout { public: ~HandleOwner17dbc0() override;
// container: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue container;
};
static_assert(sizeof(HandleOwner17dbc0)==24, "declared owner fields");
static_assert(offsetof(HandleOwner17dbc0,container)==16, "public member offset");
// HandleOwner98d8a0: GUESS(medium) STANDIN; declarations adapt include/RE/I/InventoryUpdateData.h.
class HandleOwner98d8a0 : public HandleUIRoot { public: ~HandleOwner98d8a0() override;
// inventoryRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue inventoryRef;
// updateObj: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
void* updateObj;
};
static_assert(sizeof(HandleOwner98d8a0)==32, "declared owner fields");
static_assert(offsetof(HandleOwner98d8a0,inventoryRef)==16, "public member offset");
static_assert(offsetof(HandleOwner98d8a0,updateObj)==24, "public member offset");
// HandleOwner78d9e0: GUESS(medium) STANDIN; declarations adapt include/RE/R/RefrInteraction.h.
class HandleOwner78d9e0 : public HandleSyncRoot { public: ~HandleOwner78d9e0() override;
// actor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue actor;
// targetRefr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue targetRefr;
// synced: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
bool synced;
};
static_assert(sizeof(HandleOwner78d9e0)==32, "declared owner fields");
static_assert(offsetof(HandleOwner78d9e0,actor)==16, "public member offset");
static_assert(offsetof(HandleOwner78d9e0,targetRefr)==20, "public member offset");
static_assert(offsetof(HandleOwner78d9e0,synced)==24, "public member offset");
// HandleOwner904d50: GUESS(medium) STANDIN; declarations adapt include/RE/S/StandardItemData.h.
class HandleOwner904d50 { public: virtual ~HandleOwner904d50();
// objDesc: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
void* objDesc;
// owner: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); spelling/type adapted, pointer pointee is unassessed.
HandleNativeValue owner;
};
static_assert(sizeof(HandleOwner904d50)==24, "declared owner fields");
static_assert(offsetof(HandleOwner904d50,objDesc)==8, "public member offset");
static_assert(offsetof(HandleOwner904d50,owner)==16, "public member offset");
}
