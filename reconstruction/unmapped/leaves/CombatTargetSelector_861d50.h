// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatTargetSelector.cpp:17
// CombatTargetSelector, pCombatController, CombatController, RemoveTargetSelector, CombatObject: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// CombatTargetSelector: CRASHLOGGER_PDB(59818@2026.10.24)
// unk18, DeleteThis: GUESS(low)
#pragma once

#include <cstdint>

class CombatTargetSelector;

class CombatController
{
public:
    void RemoveTargetSelector(CombatTargetSelector* a_selector);
};

class CombatObject
{
public:
    virtual ~CombatObject();
    virtual void DeleteThis();

    std::uint32_t m_uiRefCount;
};

class CombatTargetSelector : public CombatObject
{
public:
    ~CombatTargetSelector() override;  // compared: 0x861d50

    CombatController* pCombatController;
    std::uint8_t unk18[0x10];
};
static_assert(sizeof(CombatTargetSelector) == 0x28, "CombatTargetSelector size");
