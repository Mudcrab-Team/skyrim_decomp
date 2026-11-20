// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveLoadManager::Thread; size 0xc0
#pragma once

#include "BSEventFlag.h"
#include "BSTCommonStaticMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_8_136630e3.h"
#include "BSThread.h"
struct BGSSaveLoadManager__Thread {
    BSThread _base;
    bool isRunnning;
    bool isBusy;
    unsigned short pad52;
    unsigned int pad54;
    BSEventFlag haveTask;
    BSTCommonStaticMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_8_136630e3 asyncSaveLoadOperationQueue;
};
static_assert(sizeof(BGSSaveLoadManager__Thread) == 192, "BGSSaveLoadManager__Thread layout differs from the PDB");
