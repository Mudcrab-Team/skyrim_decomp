// GetFactionChanges: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Source exposure: mixed (existing community declarations and the pinned image listing).
// Code origin: partial declarations retained from the existing local extra-data prefix; new wrappers are original.
// ExtraDataList, BSExtraData, BaseExtraList, BSReadWriteLock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetByType, ExtraFactionChanges: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindOutfitExtra, OutfitExtra: GUESS(low); retain the existing public symbol-map names; returned types are partial models.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
class BSExtraData { public: virtual ~BSExtraData(); virtual std::uint32_t GetType() const; virtual bool IsNotEqual(const BSExtraData*) const; BSExtraData* next; };
struct OutfitExtra : BSExtraData {};
class ExtraFactionChanges : public BSExtraData {};
struct PresenceBitfield;
class BaseExtraList { public: virtual ~BaseExtraList(); BSExtraData* data; PresenceBitfield* presence; };
// volatile: synchronization words retained from the existing local read-write lock declaration.
class BSReadWriteLock { public: volatile std::uint32_t writerThread; volatile std::uint32_t lock; };
class ExtraDataList {
public:
    BSExtraData* GetByType(std::uint32_t a_type);
    ExtraFactionChanges* GetFactionChanges();
    BaseExtraList list;
    BSReadWriteLock lock;
};
OutfitExtra* FindOutfitExtra(ExtraDataList* a_list);
static_assert(sizeof(BaseExtraList) == 0x18, "extra-list prefix");
static_assert(offsetof(ExtraDataList, lock) == 0x18, "extra-list lock offset");
