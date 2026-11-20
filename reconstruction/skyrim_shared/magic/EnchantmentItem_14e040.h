// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// EnchantmentItem::SetCastingType, EnchantmentItem::InitFromChunk: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EnchantmentItem.cpp:74
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EnchantmentItem.cpp:99
// EnchantmentItem, MagicItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/E/EnchantmentItem.h, include/RE/M/MagicItem.h, include/RE/T/TESBoundObject.h, include/RE/T/TESForm.h, include/RE/T/TESFullName.h and include/RE/B/BGSKeywordForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class Component { public: virtual ~Component(); };
class TESForm : public Component { public: void* files; unsigned flags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; };
struct ShortPoint { short x,y,z; };
class TESBoundObject : public TESForm { public: ShortPoint min, max; unsigned pad; };
class TESFullName : public Component { public: const char* name; };
class BGSKeywordForm : public Component { public: void** keywords; unsigned count; };
template<class T> struct Array { T* data; unsigned capacity, allocatorPad, size, sizePad; };
class MagicItem : public TESBoundObject, public TESFullName, public BGSKeywordForm { public: Array<void*> effects; int hostileCount; unsigned pad; void* avEffectSetting; unsigned preloadCount, pad2; void* preloadedItem; void SetCastingType(int); };
class TESFile;
class EnchantmentItem : public MagicItem { public:
 struct Data { int costOverride; unsigned flags; int castingType, chargeOverride, delivery, spellType; float chargeTime; unsigned pad; EnchantmentItem* baseEnchantment; void* wornRestrictions; void InitFromChunk(TESFile*); } data;
 void SetCastingType(int); void InitFromChunk(TESFile*);
};
