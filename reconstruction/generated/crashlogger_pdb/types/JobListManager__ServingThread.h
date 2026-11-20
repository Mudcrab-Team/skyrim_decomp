// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: JobListManager::ServingThread; size 0x78
#pragma once

#include "BSEventFlag.h"
#include "BSTSingletonSDM_RE__JobListManager__ServingThread_5c7fd841.h"
#include "BSThread.h"
struct JobListManager__ServingThread {
    BSThread _base;
    BSTSingletonSDM_RE__JobListManager__ServingThread_5c7fd841 _base_BSTSingletonSDM_RE_JobListManager_ServingThread_;
    unsigned char undefined_51[7];
    BSEventFlag newWork;
    BSEventFlag workDone;
    unsigned char states_raw[8];
    bool bShutDown;
    bool bProcessing;
    bool bRunning;
    unsigned char undefined_73[5];
};
static_assert(sizeof(JobListManager__ServingThread) == 120, "JobListManager__ServingThread layout differs from the PDB");
