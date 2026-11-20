// Source exposure: mixed
// Origin: authorized sibling and community declarations
// PlayerCharacter::WornArmorChanged: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:2050
// TESObjectREFR::GetInventoryChanges: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); unverified mapped name
// names: GUESS(low); remaining declarations and signatures are provisional
#pragma once
class InventoryChanges { public: void SetCachedWeightDirty(); };
class TESObjectREFR {
public:
    InventoryChanges* GetInventoryChanges();
    void WornArmorChanged();
};
class PlayerCharacter : public TESObjectREFR {
public:
    void WornArmorChanged();
};
