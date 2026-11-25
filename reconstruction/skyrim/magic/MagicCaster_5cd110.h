// Source exposure: mixed (target observations; permitted sibling naming hints).
// Code origin: original; observed virtual dispatch and labelled names
// SPDX-License-Identifier: CC0-1.0
// MagicCaster, MagicCaster::GetCasterObjectReference: CRASHLOGGER_PDB(59818@2026.10.24)
// GetCasterStatsObject, GetCasterAsActor: SIBLING(fo4-private@1b765c70, author-permission)
// TESObjectREFR, Actor, MagicCaster unused virtual slots: GUESS(low) STANDIN
// MagicCaster virtual slot offsets: OBSERVED
#pragma once
class TESObjectREFR {};
class Actor : public TESObjectREFR {};
class MagicCaster
{
public:
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual TESObjectREFR* GetCasterStatsObject() const;
    virtual Actor* GetCasterAsActor() const;
    TESObjectREFR* GetCasterObjectReference(Actor** outActor) const;
};
