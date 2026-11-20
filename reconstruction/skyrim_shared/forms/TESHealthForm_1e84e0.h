// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitializeDataComponent: Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESHealthForm.cpp:17
// TESHealthForm, TESHealthForm::InitializeDataComponent: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class TESHealthForm
{
public:
    void InitializeDataComponent();
private:
    std::uint64_t unknown00;
    std::uint32_t health;
};
