// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuControls; size 0x88
#pragma once

#include "BSTArray_RE__MenuControls__QueuedReg_a84cf6e6.h"
#include "BSTArray_RE__MenuEventHandler_6f7b6628.h"
#include "BSTEventSink_RE__InputEvent_e78270ba.h"
#include "BSTEventSink_RE__MenuModeChangeEvent_37ac473d.h"
#include "BSTSingletonSDM_RE__MenuControls_17163d8b.h"
struct ClickHandler;
struct ConsoleOpenHandler;
struct DirectionHandler;
struct FavoritesHandler;
struct MenuOpenHandler;
struct QuickSaveLoadHandler;
struct ScreenshotHandler;
struct MenuControls {
    BSTEventSink_RE__InputEvent_e78270ba _base;
    BSTEventSink_RE__MenuModeChangeEvent_37ac473d _base_BSTEventSink_RE_MenuModeChangeEvent_;
    BSTSingletonSDM_RE__MenuControls_17163d8b _base_BSTSingletonSDM_RE_MenuControls_;
    unsigned char pad11;
    unsigned short pad12;
    unsigned int pad14;
    BSTArray_RE__MenuEventHandler_6f7b6628 handlers;
    BSTArray_RE__MenuControls__QueuedReg_a84cf6e6 regBuffer;
    ClickHandler* clickHandler;
    DirectionHandler* directionHandler;
    ConsoleOpenHandler* consoleOpenHandler;
    QuickSaveLoadHandler* quickSaveLoadHandler;
    MenuOpenHandler* menuOpenHandler;
    FavoritesHandler* favoritesHandler;
    ScreenshotHandler* screenshotHandler;
    bool isProcessing;
    bool beastForm;
    bool remapMode;
    unsigned char unk83;
    unsigned int unk84;
};
static_assert(sizeof(MenuControls) == 136, "MenuControls layout differs from the PDB");
