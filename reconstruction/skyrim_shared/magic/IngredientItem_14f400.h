// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// IngredientItem::CopyMagicItemData: SIBLING(fo4-private@1b765c70, author-permission); adapted data copying.
// IngredientItem::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted reset.
// IngredientItem::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted loading.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:341
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:258
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:250
// IngredientItem and bases: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class BGSLoadFormBuffer;
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent {
public:
    void LoadGame(BGSLoadFormBuffer*); void Revert(BGSLoadFormBuffer*);
    void* sourceFiles; std::uint32_t formFlags, formID; std::uint16_t inGameFlags;
    std::uint8_t formType, pad1b; std::uint32_t pad1c;
};
struct BoundData { std::int16_t minimum[3], maximum[3]; };
class TESBoundObject : public TESForm { public: BoundData bound; std::uint32_t pad2c; };
class TESFullName : public BaseFormComponent { public: const char* fullName; };
class BGSKeywordForm : public BaseFormComponent { public: void* keywords; std::uint32_t count, pad; };
class MagicItem : public TESBoundObject, public TESFullName, public BGSKeywordForm {
public:
    void* effects; std::uint32_t capacity, pad64, count, pad6c;
    std::int32_t hostileCount; std::uint32_t pad74; void* avEffectSetting;
    std::uint32_t preloadCount, pad84; void* preloadedItem;
};
class TESModel : public BaseFormComponent { public: const char* model; void* textures; void* addons; std::uint16_t numTextures, numAddons; std::uint32_t pad; };
class TESModelTextureSwap : public TESModel { public: void* alternateTextures; std::uint32_t count,pad; };
class TESIcon : public BaseFormComponent { public: const char* textureName; };
class TESWeightForm : public BaseFormComponent { public: float weight; };
class BGSEquipType : public BaseFormComponent { public: void* equipSlot; };
class BGSDestructibleObjectForm : public BaseFormComponent { public: void* data; };
class BGSPickupPutdownSounds : public BaseFormComponent { public: void* pickupSound; void* putdownSound; };
class TESValueForm : public BaseFormComponent { public: std::int32_t value; };
class BGSLoadGameBuffer {
public:
    virtual ~BGSLoadGameBuffer(); void LoadDataEndian(void*, std::uint32_t, std::uint32_t);
    void* buffer; std::uint64_t unk10; std::uint32_t unk18, unk1c, unk20, position;
};
class BGSLoadFormBuffer : public BGSLoadGameBuffer {
public:
    std::uint32_t formID, size, uncompressedSize, pad; TESForm* form;
    std::uint32_t changeFlags, oldChangeFlags;
};
class IngredientItem : public MagicItem, public TESModelTextureSwap, public TESIcon, public TESWeightForm,
    public BGSEquipType, public BGSDestructibleObjectForm, public BGSPickupPutdownSounds, public TESValueForm {
public:
    struct Data { std::int32_t costOverride; std::uint32_t flags; } data;
    struct GameData { std::uint16_t knownEffectFlags, playerUses; } gamedata;
    void CopyMagicItemData(MagicItem* other); void Revert(BGSLoadFormBuffer*); void LoadGame(BGSLoadFormBuffer*);
};
