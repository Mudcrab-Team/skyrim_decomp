// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpPhantomCallbackShape; size 0x20
#pragma once
struct hkpPhantomCallbackShape {
    char32_t* vftable;
    short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int pad0C;
    unsigned long long m_userData;
    unsigned int m_type;
    unsigned int pad1C;
};
static_assert(sizeof(hkpPhantomCallbackShape) == 32, "hkpPhantomCallbackShape layout differs from the PDB");
