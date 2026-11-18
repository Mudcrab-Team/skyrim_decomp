// Source exposure: mixed (community declarations and local target binding).
// Code origin: data declarations adapted from pinned public CommonLibSSE-NG headers. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSPointerHandle.h, BSTMessageQueue.h, BSExtraData.h; I/IUIMessageData.h, S/SyncQueueObj.h and the corresponding named handle-owner headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// QueueDeleteLayout: GUESS(medium) STANDIN; public queue interface alias.
// lock, numEntries, pushIdx, popIdx: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// entries: GUESS(medium) STANDIN; pointer-valued raw queue slots, with lifetime/ownership management unassessed.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// QueueDeleteLayout, QueueCommonDelete0: GUESS(medium) STANDIN; incomplete method sets.
class QueueDeleteLayout { public: virtual ~QueueDeleteLayout(); };
class QueueCommonDelete0 : public QueueDeleteLayout { public: ~QueueCommonDelete0() override; mutable volatile std::uint32_t lock; };
static_assert(sizeof(QueueCommonDelete0)==16, "public common queue lock");
static_assert(offsetof(QueueCommonDelete0,lock)==8, "lock offset");
// QueueDeleteLayout1, QueueCommonDelete1: GUESS(medium) STANDIN; incomplete method sets.
class QueueDeleteLayout1 { public: virtual ~QueueDeleteLayout1(); };
class QueueCommonDelete1 : public QueueDeleteLayout1 { public: ~QueueCommonDelete1() override; mutable volatile std::uint32_t lock; };
static_assert(sizeof(QueueCommonDelete1)==16, "public common queue lock");
static_assert(offsetof(QueueCommonDelete1,lock)==8, "lock offset");
// QueueDeleteLayout2, QueueCommonDelete2: GUESS(medium) STANDIN; incomplete method sets.
class QueueDeleteLayout2 { public: virtual ~QueueDeleteLayout2(); };
class QueueCommonDelete2 : public QueueDeleteLayout2 { public: ~QueueCommonDelete2() override; mutable volatile std::uint32_t lock; };
static_assert(sizeof(QueueCommonDelete2)==16, "public common queue lock");
static_assert(offsetof(QueueCommonDelete2,lock)==8, "lock offset");
// QueueDeleteLayout3, QueueCommonDelete3: GUESS(medium) STANDIN; incomplete method sets.
class QueueDeleteLayout3 { public: virtual ~QueueDeleteLayout3(); };
class QueueCommonDelete3 : public QueueDeleteLayout3 { public: ~QueueCommonDelete3() override; mutable volatile std::uint32_t lock; };
static_assert(sizeof(QueueCommonDelete3)==16, "public common queue lock");
static_assert(offsetof(QueueCommonDelete3,lock)==8, "lock offset");
// QueueDeleteLayout4, QueueCommonDelete4: GUESS(medium) STANDIN; incomplete method sets.
class QueueDeleteLayout4 { public: virtual ~QueueDeleteLayout4(); };
class QueueCommonDelete4 : public QueueDeleteLayout4 { public: ~QueueCommonDelete4() override; mutable volatile std::uint32_t lock; };
static_assert(sizeof(QueueCommonDelete4)==16, "public common queue lock");
static_assert(offsetof(QueueCommonDelete4,lock)==8, "lock offset");
// QueueDeleteLayout5, QueueCommonDelete5: GUESS(medium) STANDIN; incomplete method sets.
class QueueDeleteLayout5 { public: virtual ~QueueDeleteLayout5(); };
class QueueCommonDelete5 : public QueueDeleteLayout5 { public: ~QueueCommonDelete5() override; mutable volatile std::uint32_t lock; };
static_assert(sizeof(QueueCommonDelete5)==16, "public common queue lock");
static_assert(offsetof(QueueCommonDelete5,lock)==8, "lock offset");
// QueueDeleteLayout6, QueueCommonDelete6: GUESS(medium) STANDIN; incomplete method sets.
class QueueDeleteLayout6 { public: virtual ~QueueDeleteLayout6(); };
class QueueCommonDelete6 : public QueueDeleteLayout6 { public: ~QueueCommonDelete6() override; mutable volatile std::uint32_t lock; };
static_assert(sizeof(QueueCommonDelete6)==16, "public common queue lock");
static_assert(offsetof(QueueCommonDelete6,lock)==8, "lock offset");
// QueueDeleteLayout7, QueueCommonDelete7: GUESS(medium) STANDIN; incomplete method sets.
class QueueDeleteLayout7 { public: virtual ~QueueDeleteLayout7(); };
class QueueCommonDelete7 : public QueueDeleteLayout7 { public: ~QueueCommonDelete7() override; mutable volatile std::uint32_t lock; };
static_assert(sizeof(QueueCommonDelete7)==16, "public common queue lock");
static_assert(offsetof(QueueCommonDelete7,lock)==8, "lock offset");
// QueueStaticDelete62dcd0: GUESS(medium) STANDIN; public queue capacity8 independently decoded from owner RTTI.
class QueueStaticDelete62dcd0 : public QueueCommonDelete0 { public: ~QueueStaticDelete62dcd0() override; void* entries[8]; std::uint32_t numEntries; std::uint32_t pushIdx; std::uint32_t popIdx; };
static_assert(sizeof(QueueStaticDelete62dcd0)==96, "typed queue entries and counters");
static_assert(offsetof(QueueStaticDelete62dcd0,entries)==16, "entry storage offset");
static_assert(offsetof(QueueStaticDelete62dcd0,numEntries)==80, "counter offset");
// QueueStaticDeletebc3bd0: GUESS(medium) STANDIN; public queue capacity128 independently decoded from owner RTTI.
class QueueStaticDeletebc3bd0 : public QueueCommonDelete3 { public: ~QueueStaticDeletebc3bd0() override; void* entries[128]; std::uint32_t numEntries; std::uint32_t pushIdx; std::uint32_t popIdx; };
static_assert(sizeof(QueueStaticDeletebc3bd0)==1056, "typed queue entries and counters");
static_assert(offsetof(QueueStaticDeletebc3bd0,entries)==16, "entry storage offset");
static_assert(offsetof(QueueStaticDeletebc3bd0,numEntries)==1040, "counter offset");
// QueueStaticDelete116cb30: GUESS(medium) STANDIN; public queue capacity100 independently decoded from owner RTTI.
class QueueStaticDelete116cb30 : public QueueCommonDelete4 { public: ~QueueStaticDelete116cb30() override; void* entries[100]; std::uint32_t numEntries; std::uint32_t pushIdx; std::uint32_t popIdx; };
static_assert(sizeof(QueueStaticDelete116cb30)==832, "typed queue entries and counters");
static_assert(offsetof(QueueStaticDelete116cb30,entries)==16, "entry storage offset");
static_assert(offsetof(QueueStaticDelete116cb30,numEntries)==816, "counter offset");
// QueueStaticDelete11f78f0: GUESS(medium) STANDIN; public queue capacity256 independently decoded from owner RTTI.
class QueueStaticDelete11f78f0 : public QueueCommonDelete5 { public: ~QueueStaticDelete11f78f0() override; void* entries[256]; std::uint32_t numEntries; std::uint32_t pushIdx; std::uint32_t popIdx; };
static_assert(sizeof(QueueStaticDelete11f78f0)==2080, "typed queue entries and counters");
static_assert(offsetof(QueueStaticDelete11f78f0,entries)==16, "entry storage offset");
static_assert(offsetof(QueueStaticDelete11f78f0,numEntries)==2064, "counter offset");
}
