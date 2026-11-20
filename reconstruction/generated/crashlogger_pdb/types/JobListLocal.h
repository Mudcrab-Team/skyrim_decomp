// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: JobListLocal; size 0xd8
#pragma once

#include "BSEventFlag.h"
#include "BSFixedString_char_83b572b4.h"
#include "BSTArray_RE__BSJobs__JobListLocal__JobInstance_35a898d8.h"
#include "BSTArray_RE__BSTAtomicValue_long_long_8611932a.h"
#include "BSTArray_RE__BSTAtomicValue_unsigned_int_b6570cb1.h"
#include "BSTAtomicValue_long_long_b28030a7.h"
struct JobListLocal {
    BSTArray_RE__BSJobs__JobListLocal__JobInstance_35a898d8 jobArray;
    BSTArray_RE__BSTAtomicValue_long_long_8611932a signalJobCountArray;
    BSTArray_RE__BSTAtomicValue_long_long_8611932a signalJobCountArrayStatic;
    BSTArray_RE__BSTAtomicValue_unsigned_int_b6570cb1 stalledJobCountArray;
    BSFixedString_char_83b572b4 name;
    BSEventFlag threadSignOffEvent;
    unsigned char doneGuards_raw[32];
    BSTAtomicValue_long_long_b28030a7 currentJob;
    BSTAtomicValue_long_long_b28030a7 numThreadsSignedUp;
    BSTAtomicValue_long_long_b28030a7 version;
    BSTAtomicValue_long_long_b28030a7* waitForGuard;
    BSEventFlag* eventFlag;
    unsigned int numSyncs;
    unsigned int maxJobs;
    unsigned int batchSize;
    unsigned int lastSignalJob;
    unsigned int currentDoneGuard;
    unsigned int usedThreads;
    unsigned int flags;
    unsigned char overallPriority;
    unsigned char undefined_d5[3];
};
static_assert(sizeof(JobListLocal) == 216, "JobListLocal layout differs from the PDB");
