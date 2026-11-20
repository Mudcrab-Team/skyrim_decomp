// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Main; size 0x270
#pragma once

#include "BSPackedTaskQueue.h"
#include "BSTEventSink_RE__BSGamerProfileEvent_9d3066b0.h"
#include "BSTEventSink_RE__PositionPlayerEvent_141ac998.h"
#include "ScrapHeap_aea37981.h"
struct HINSTANCE;
struct HWND;
struct Main {
    BSTEventSink_RE__PositionPlayerEvent_141ac998 _base;
    BSTEventSink_RE__BSGamerProfileEvent_9d3066b0 _base_BSTEventSink_RE_BSGamerProfileEvent_;
    bool quitGame;
    bool resetGame;
    bool fullReset;
    bool gameActive;
    bool onIdle;
    bool reloadContent;
    bool freezeTime;
    bool freezeNextFrame;
    HWND* wnd;
    HINSTANCE* instance;
    unsigned int threadID;
    unsigned int unk02C;
    unsigned long long unk030;
    ScrapHeap_aea37981 packedTaskHeap;
    BSPackedTaskQueue taskQueue;
    ScrapHeap_aea37981 secondaryPackedTaskHeap;
    BSPackedTaskQueue secondaryTaskQueue;
    unsigned char unk1D8;
    unsigned char unk1D9;
    unsigned short unk1DA;
    unsigned int unk1DC;
    unsigned char saveDataBackgroundImages_raw[72];
    unsigned char saveDataIconImages_raw[72];
};
static_assert(sizeof(Main) == 624, "Main layout differs from the PDB");
