// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CraftingMenu__VFTable; size 0x48
#pragma once

struct FxDelegateHandler;
struct GRefCountImplCore;
struct IMenu;
struct CraftingMenu__VFTable {
    long long (*dtor_0)(GRefCountImplCore* , char);
    unsigned long long*(*dtor_8)(FxDelegateHandler* , char);
    void (*PostCreate_10)(void);
    void (*Func3_18)(void);
    long long (*ProcessMessage_20)(IMenu* , long long);
    unsigned int (*AdvanceMovie_28)(long long, long long, int, long long);
    int (*PostDisplay_30)(IMenu* );
    void (*PreDisplay_38)(void);
    int (*RefreshPlatform_40)(IMenu* );
};
static_assert(sizeof(CraftingMenu__VFTable) == 72, "CraftingMenu__VFTable layout differs from the PDB");
