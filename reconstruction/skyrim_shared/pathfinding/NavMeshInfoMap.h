// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NavMeshInfoMap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/TESForm.h"
inline BaseFormComponent::~BaseFormComponent() {}
// ArrayOwner, ClearArray, ResetArrayCount, ReleaseArray: GUESS(low); represented heap array ownership.
void ClearArray(void*); void ResetArrayCount(std::uint32_t*); void ReleaseArray(void*);
struct ArrayOwner {
 void** data; std::uint32_t capacity; std::uint32_t allocatorState; std::uint32_t count; std::uint32_t unknown14;
 ~ArrayOwner() { if(data) { ClearArray(this); count=0; } else ResetArrayCount(&count); ReleaseArray(this); }
};
static_assert(sizeof(ArrayOwner)==0x18,"heap array size");
struct NavEntry { std::uint64_t key; void* value; NavEntry* next; };
struct NavMapTail { ~NavMapTail(); std::uint32_t unknown00,capacity,freeCount,good; NavEntry* sentinel; std::uint64_t allocatorState; NavEntry* entries; };
struct CKMapTail { ~CKMapTail(); std::uint32_t unknown00,capacity,freeCount,good; NavEntry* sentinel; std::uint64_t allocatorState; NavEntry* entries; };
struct NavMap { std::uint64_t unknown00; NavMapTail tail; }; struct CKMap { std::uint64_t unknown00; CKMapTail tail; };
template<class T> struct BSTSingletonExplicit {};
struct PrecomputedPaths : public BSTSingletonExplicit<PrecomputedPaths> { ~PrecomputedPaths(); ArrayOwner allPaths; NavMap infoToIndexMap; };
class BSNavmeshInfoMap : public BSTSingletonExplicit<BSNavmeshInfoMap> { public: BSNavmeshInfoMap(); virtual ~BSNavmeshInfoMap(); };
class NavMeshInfoMap : public TESForm, public BSNavmeshInfoMap, public PrecomputedPaths { public: NavMeshInfoMap(); ~NavMeshInfoMap() override; virtual void SetAltered(bool); bool updateAll; NavMap infoMap; CKMap ckNavMeshInfoMap; std::uint32_t lockThread,lockState; bool init; }; static_assert(sizeof(NavMeshInfoMap)==0xF0,"navmesh map size");
void ClearNavMap(NavMeshInfoMap*); void BaseSetAltered(TESForm*,bool); void LockNavMap(void*); void UnlockNavMap(void*); void SetNavInfoAltered(void*,bool);


struct NavWriteScope { void* lock; explicit NavWriteScope(void* value):lock(value) { LockNavMap(lock); } ~NavWriteScope() { if(lock) UnlockNavMap(lock); } };
