// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QueuedPromoteLocationReferencesTask__VFTable; size 0x48
#pragma once

struct QueuedPromoteReferencesTask;
struct QueuedPromoteLocationReferencesTask__VFTable {
    long long (*Func0_0)(QueuedPromoteReferencesTask* , char);
    void (*Func1_8)(QueuedPromoteReferencesTask* );
    unsigned long (*Func2_10)(QueuedPromoteReferencesTask* );
    unsigned long (*Func3_18)(QueuedPromoteReferencesTask* , int);
    char (*Func4_20)(long long, char* , unsigned int);
    char (*Func5_28)(void);
    void (*Func6_30)(void);
    long long (*Func7_38)(long long);
    char (*Func8_40)(long long, int);
};
static_assert(sizeof(QueuedPromoteLocationReferencesTask__VFTable) == 72, "QueuedPromoteLocationReferencesTask__VFTable layout differs from the PDB");
