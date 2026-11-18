// Code origin: original reconstruction; declarations adapted from pinned MIT community headers.
// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GMemoryHeap: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HeapSlot1, HeapSlot2, HeapSlot3, HeapSlot4, HeapSlot5, HeapSlot6, HeapSlot7, HeapSlot8, HeapSlot9, HeapSlot10, HeapSlot11, GlobalHeap: GUESS(low)
class GMemoryHeap { public: virtual ~GMemoryHeap(); virtual void HeapSlot1(); virtual void HeapSlot2(); virtual void HeapSlot3(); virtual void HeapSlot4(); virtual void HeapSlot5(); virtual void HeapSlot6(); virtual void HeapSlot7(); virtual void HeapSlot8(); virtual void HeapSlot9(); virtual void HeapSlot10(); virtual void HeapSlot11(); virtual void Free(void*); };
extern GMemoryHeap* GlobalHeap;
// BSScaleformTranslator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
class GRefCountImpl { public: virtual ~GRefCountImpl(); std::int32_t refCount; };
class GFxState : public GRefCountImpl { public: ~GFxState() override {} std::uint32_t stateType; };
class GFxTranslator : public GFxState { public: ~GFxTranslator() override {} virtual void GetCaps(); virtual void Translate(void*); virtual void OnWordWrapping(void*); std::uint32_t wwMode; };
struct WideString { ~WideString(); const wchar_t* value; };
struct TranslationEntry { WideString key,value; TranslationEntry* next; };
extern std::uint32_t TranslationHeapState; extern std::uint64_t TranslationHeapManager;
void InitializeTranslationHeap(void*,std::uint32_t*); void DeallocateTranslationHeap(void*,void*,bool); void DestroyTranslationPair(WideString*,WideString*);
struct TranslationMap { std::uint64_t unknown00; std::uint32_t unknown08,capacity,freeCount,good; TranslationEntry* sentinel; std::uint64_t allocatorState; TranslationEntry* entries;

};
class BSScaleformTranslator : public GFxTranslator { public: BSScaleformTranslator(); ~BSScaleformTranslator() override; static void operator delete(void* ptr) { GlobalHeap->Free(ptr); } TranslationMap translator; }; static_assert(sizeof(BSScaleformTranslator)==0x50,"scaleform translator size");

