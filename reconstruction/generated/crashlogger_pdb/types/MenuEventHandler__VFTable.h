// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuEventHandler__VFTable; size 0x30
#pragma once

struct MenuEventHandler_95ed2a85;
struct MenuEventHandler__VFTable {
    unsigned long long*(*dtor_0)(MenuEventHandler_95ed2a85* , char);
    int (*CanProcess_8)(void);
    char (*ProcessKinect_10)(void);
    char (*ProcessThumbstick_18)(void);
    char (*ProcessMouseMove_20)(void);
    char (*ProcessButton_28)(void);
};
static_assert(sizeof(MenuEventHandler__VFTable) == 48, "MenuEventHandler__VFTable layout differs from the PDB");
