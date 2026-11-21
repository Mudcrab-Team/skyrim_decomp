// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: JobList; size 0x8
#pragma once

struct JobListLocal;
struct JobList {
    JobListLocal* jobList;
};
static_assert(sizeof(JobList) == 8, "JobList layout differs from the PDB");
