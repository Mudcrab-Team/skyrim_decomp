// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ResetEntryAgents: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); sibling name, identity with this function unproven
// Globals: GUESS(low); placeholder name
#pragma once

struct D3FE10Entry;
struct D3FE10Header;
struct D3FE10Manager;


struct D3FE10Agent {
    unsigned short m_flags;
    unsigned short m_iOwnerObjectOffset;
};

struct D3FE10Entry {
    D3FE10Agent m_pAgents[8];
    unsigned char unk20;
    unsigned char m_numAgents;
    unsigned short unk22;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

struct D3FE10Header {
    unsigned short unk00;
    unsigned char m_iNumberOfEntries;
};

class D3FE10Manager {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void ResetAgent(unsigned short id, void* pkInfo);
};

struct Globals
{
};
