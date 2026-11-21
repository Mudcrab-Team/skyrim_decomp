// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DXGI_RATIONAL; size 0x8
#pragma once
struct DXGI_RATIONAL {
    unsigned int Numerator;
    unsigned int Denominator;
};
static_assert(sizeof(DXGI_RATIONAL) == 8, "DXGI_RATIONAL layout differs from the PDB");
