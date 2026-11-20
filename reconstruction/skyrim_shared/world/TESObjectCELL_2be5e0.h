// TESObjectCELL: GUESS(low) STANDIN
/*
 * TESObjectCELL: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x2be5e0 26 bytes; RVA 0x2c4050 31 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis, community-headers.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); unverified against this build.
 * No external body adapted. Partial interfaces are stand-ins.
 */
#pragma once

/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#include <cstdint>
// BaseFormComponent, TESForm, TESFullName, BGSKeywordForm, BGSLocation, BSTArrayBase, BSTArrayHeapAllocator, BSTArray, BSFixedString, ObjectRefHandle, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESObjectCELL::GetLocation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESObjectCELL::LocationCleared: GUESS(low) STANDIN
// Partial interfaces omit virtual methods and later fields not needed by the compared function.
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent() = 0; virtual void ClearDataComponent() = 0; virtual void CopyComponent(BaseFormComponent*); };
class TESFileArray; class BGSKeyword; class TESFaction; class BGSMusicType; class OverrideData; class QueuedPromoteLocationReferencesTask; struct SpecialRefData; struct UniqueNPCData;
class BSFixedString { const char* data; };
class TESForm : public BaseFormComponent { public: TESFileArray* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
class TESFullName : public BaseFormComponent { public: BSFixedString fullName; };
class BGSKeywordForm : public BaseFormComponent { public: BGSKeyword** keywords; std::uint32_t numKeywords; std::uint32_t pad14; };
class BSTArrayBase { protected: std::uint32_t _size; };
class BSTArrayHeapAllocator { protected: void* _data; std::uint32_t _capacity; };
template<class T> class BSTArray : public BSTArrayHeapAllocator, public BSTArrayBase {};
template<class T> class NiPointer { public: T* pointer; };
class ObjectRefHandle { public: std::uint32_t value; };
class BGSLocation : public TESForm, public TESFullName, public BGSKeywordForm { public:
    struct KEYWORD_DATA { BGSKeyword* keyword; float data; std::uint32_t pad0C; };
    BGSLocation* parentLoc; TESFaction* unreportedCrimeFaction; BGSMusicType* musicType; ObjectRefHandle worldLocMarker; float worldLocRadius; ObjectRefHandle horseLocMarker; std::uint32_t pad6C;
    BSTArray<SpecialRefData> specialRefs; BSTArray<UniqueNPCData> uniqueNPCs; OverrideData* overrideData; NiPointer<QueuedPromoteLocationReferencesTask> promoteRefsTask;
    BSTArray<ObjectRefHandle> promotedRefs; volatile std::int32_t loadedCount; std::uint32_t fileOffset; BSTArray<KEYWORD_DATA> keywordData;
    std::uint32_t lastChecked; bool cleared; bool everCleared; std::uint16_t padEE;
};
class BSExtraData;
class BaseExtraList { public: struct PresenceBitfield; virtual ~BaseExtraList(); BSExtraData* data; PresenceBitfield* presence; };
class BSReadWriteLock { public: volatile std::uint32_t _writerThread; volatile std::uint32_t _lock; };
class BSSpinLock { public: volatile std::uint32_t _owningThread; volatile std::uint32_t _lockCount; };
class ExtraDataList { public: std::int32_t GetRank(); BaseExtraList _extraData; BSReadWriteLock _lock; };
class TESObjectCELL : public TESForm, public TESFullName { public:
    BGSLocation* GetLocation(); bool LocationCleared(); std::int32_t CellRank();
    BSSpinLock grassCreateLock; BSSpinLock grassTaskLock; std::uint16_t cellFlags; std::uint16_t cellGameFlags; std::uint8_t cellState;
    bool autoWaterLoaded; bool cellDetached; std::uint8_t pad047; ExtraDataList extraList;
};
static_assert(sizeof(TESForm) == 0x20, "TESForm size");
static_assert(sizeof(TESFullName) == 0x10, "TESFullName size");
static_assert(sizeof(BGSKeywordForm) == 0x18, "BGSKeywordForm size");
static_assert(sizeof(BSTArray<void*>) == 0x18, "BSTArray size");
static_assert(sizeof(BGSLocation) == 0xf0, "BGSLocation size");
// BaseFormComponent::InitializeDataComponent, BaseFormComponent::ClearDataComponent, BaseFormComponent::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESForm::sourceFiles, TESForm::formFlags, TESForm::formID, TESForm::inGameFormFlags, TESForm::formType, TESForm::pad1B, TESForm::pad1C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESFullName::fullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSKeywordForm::keywords, BGSKeywordForm::numKeywords, BGSKeywordForm::pad14: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSTArrayBase::_size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSTArrayHeapAllocator::_data, BSTArrayHeapAllocator::_capacity: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSLocation::parentLoc, BGSLocation::unreportedCrimeFaction, BGSLocation::musicType, BGSLocation::worldLocMarker, BGSLocation::worldLocRadius, BGSLocation::horseLocMarker, BGSLocation::pad6C, BGSLocation::specialRefs: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSLocation::uniqueNPCs, BGSLocation::overrideData, BGSLocation::promoteRefsTask, BGSLocation::promotedRefs, BGSLocation::loadedCount, BGSLocation::fileOffset, BGSLocation::keywordData, BGSLocation::lastChecked: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSLocation::cleared, BGSLocation::everCleared, BGSLocation::padEE: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSLocation::KEYWORD_DATA::keyword, BGSLocation::KEYWORD_DATA::data, BGSLocation::KEYWORD_DATA::pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESFileArray, BGSKeyword, TESFaction, BGSMusicType, OverrideData, QueuedPromoteLocationReferencesTask, SpecialRefData, UniqueNPCData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ObjectRefHandle::value, NiPointer::pointer: GUESS(low) STANDIN

// BaseExtraList, BaseExtraList::PresenceBitfield, BaseExtraList::data, BaseExtraList::presence, BSReadWriteLock, BSReadWriteLock::_writerThread, BSReadWriteLock::_lock, BSSpinLock, BSSpinLock::_owningThread, BSSpinLock::_lockCount, ExtraDataList, ExtraDataList::_extraData, ExtraDataList::_lock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESObjectCELL::grassCreateLock, TESObjectCELL::grassTaskLock, TESObjectCELL::cellFlags, TESObjectCELL::cellGameFlags, TESObjectCELL::cellState, TESObjectCELL::autoWaterLoaded, TESObjectCELL::cellDetached, TESObjectCELL::pad047, TESObjectCELL::extraList, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ExtraDataList::GetRank: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91, permission)
// TESObjectCELL::CellRank: GUESS(low) STANDIN
