// Origin: adapted declarations from powerof3/CommonLibSSE, GPL-3.0, 654e55f7979c1733033d5dbef176e43827bac944.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// MagicItemData: EXE_RTTI
// Declarations adapted from powerof3/CommonLibSSE under GPL-3.0.
#pragma once
#include <cstdint>
// MagicItemData, GetFavorite, BSString, effectDesc, baseForm, MagicFavorites: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0)
// IsFavorite, magicFavorites, data, size, capacity: GUESS(low)
class TESForm;
class MagicFavorites { public: std::uint8_t IsFavorite(TESForm* form); };
extern MagicFavorites* magicFavorites;
class BSString { public: char* data; std::uint16_t size, capacity; };
class MagicItemData {
public:
 virtual ~MagicItemData();
 bool GetFavorite();
 BSString effectDesc;
 TESForm* baseForm;
};
