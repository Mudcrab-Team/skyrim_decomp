// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpBroadPhaseListener: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpBroadPhaseListener::removeCollisionPair_140A9CF00: CRASHLOGGER_PDB(59818@2026.10.24)
// Globals: GUESS(low); placeholder name
#pragma once

struct D10860Agent;
struct D10860Collidable;
struct D10860HandlePair;
struct D10860TypedHandle;



struct D10860Collidable;

struct D10860TypedHandle
{
    int m_iOwnerObjectOffset;
    unsigned char m_type;
    signed char m_iOwnerOffset;

    D10860Collidable* getOwner() const
    {
        return reinterpret_cast<D10860Collidable*>(const_cast<char*>(reinterpret_cast<const char*>(this)) +
                                                   m_iOwnerOffset);
    }
};

struct D10860HandlePair
{
    D10860TypedHandle* m_kPointA;
    D10860TypedHandle* m_kPointB;
};

struct D10860Agent;

D10860Agent* FindEntryValue(const D10860Collidable* collA, const D10860Collidable* collB);
void Func00cc10b0(D10860Agent* agent);

struct hkpBroadPhaseListener
{
    void removeCollisionPair_140A9CF00(D10860HandlePair& pair);
};

struct Globals
{
};
