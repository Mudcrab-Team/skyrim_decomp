// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FACTION_VENDOR_DATA_VALUES; size 0xc
#pragma once
struct FACTION_VENDOR_DATA_VALUES {
    unsigned short startHour;
    unsigned short endHour;
    unsigned int locationRadius;
    bool buysStolen;
    bool notBuySell;
    bool buysNonStolen;
    unsigned char padB;
};
static_assert(sizeof(FACTION_VENDOR_DATA_VALUES) == 12, "FACTION_VENDOR_DATA_VALUES layout differs from the PDB");
