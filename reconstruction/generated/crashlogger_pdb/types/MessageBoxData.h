// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MessageBoxData; size 0x50
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "BSTArray_RE__BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_246865ef.h"
#include "BSTSmartPointer_RE__IMessageBoxCallback_a6f63335.h"
#include "IUIMessageData.h"
struct MessageBoxData {
    IUIMessageData _base;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce bodyText;
    BSTArray_RE__BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_246865ef buttonText;
    int warningType;
    int cancelButtonIndex;
    BSTSmartPointer_RE__IMessageBoxCallback_a6f63335 callback;
    int menuDepth;
    unsigned char buttonPressOffset;
    bool useHtml;
    bool verticalButtons;
    bool isCancellable;
};
static_assert(sizeof(MessageBoxData) == 80, "MessageBoxData layout differs from the PDB");
