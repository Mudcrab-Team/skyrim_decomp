// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Info; size 0x30
#pragma once
struct Info {
    unsigned long long minAlign;
    unsigned long long maxAlign;
    unsigned long long granularity;
    unsigned long long sysDirectThreshold;
    unsigned long long maxHeapGranularity;
    bool hasRealloc;
    unsigned char undefined_29[7];
};
static_assert(sizeof(Info) == 48, "Info layout differs from the PDB");
