// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: JobInstance; size 0x10
#pragma once
struct JobInstance {
    unsigned char func_raw[8];
    void* data;
};
static_assert(sizeof(JobInstance) == 16, "JobInstance layout differs from the PDB");
