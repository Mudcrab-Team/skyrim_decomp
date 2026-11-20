// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UIMessage; size 0x20
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "UI_MESSAGE_TYPE.h"
struct IUIMessageData;
struct UIMessage {
    BSFixedString_char_83b572b4 menu;
    UI_MESSAGE_TYPE type;
    unsigned int pad0C;
    IUIMessageData* data;
    bool isPooled;
    unsigned char pad19;
    unsigned short pad1A;
    unsigned int pad1C;
};
static_assert(sizeof(UIMessage) == 32, "UIMessage layout differs from the PDB");
