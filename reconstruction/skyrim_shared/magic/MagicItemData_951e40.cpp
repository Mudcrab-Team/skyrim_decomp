// Origin: adapted declarations from powerof3/CommonLibSSE, GPL-3.0, 654e55f7979c1733033d5dbef176e43827bac944.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// MagicItemData: EXE_RTTI
// Declarations adapted from powerof3/CommonLibSSE under GPL-3.0.
// 0x951e40 MagicItemData::GetFavorite
#include "MagicItemData_951e40.h"
bool MagicItemData::GetFavorite() {
 bool favorite = false;
 if (magicFavorites->IsFavorite(baseForm)) favorite = true;
 return favorite;
}
