// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: threadmbcinfostruct; size 0x228
#pragma once
struct threadmbcinfostruct {
    int refcount;
    int mbcodepage;
    int ismbcodepage;
    unsigned short mbulinfo[6];
    unsigned char mbctype[257];
    unsigned char mbcasemap[256];
    unsigned char _pad_0[7];
    wchar_t* mblocalename;
};
static_assert(sizeof(threadmbcinfostruct) == 552, "threadmbcinfostruct layout differs from the PDB");
