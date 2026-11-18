// Source exposure: community-headers
// Code origin: public lock fields and enum widths adapted to storage-only declarations; no method bodies.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BSAtomic.h,M/MagicSystem.h,E/EffectArchetypes.h,D/DisguiseEffect.h,A/ActionInput.h,B/BSStorage.h}; MIT.
// BSReadWriteLock, SpellType, EffectArchetype: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DisguiseStateStorageLayout, ExtraStorageValueTypesLayout: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "LayoutValueTypes.h"
namespace ResearchLayouts {
using uint16_t=std::uint16_t;
using uint32_t=std::uint32_t;
namespace MagicSystem { enum class SpellType : std::int32_t {}; }
enum class EffectArchetype : std::int32_t {};
enum class DisguiseStateStorageLayout : std::int32_t {};
struct BSReadWriteLock { volatile std::uint32_t _writerThread; volatile std::uint32_t _lock; };
static_assert(sizeof(BSReadWriteLock)==8,"public lock storage");
static_assert(offsetof(BSReadWriteLock,_writerThread)==0,"public writer identity offset");
static_assert(offsetof(BSReadWriteLock,_lock)==4,"public lock word offset");
static_assert(sizeof(MagicSystem::SpellType)==4,"public enum width");
static_assert(sizeof(EffectArchetype)==4,"public enum width");
static_assert(sizeof(DisguiseStateStorageLayout)==4,"public enum width");
class ExtraStorageValueTypesLayout {};
}
