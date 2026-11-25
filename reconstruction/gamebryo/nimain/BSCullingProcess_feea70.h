// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSCullingProcess::TakePendingCullingProcess, JobList::Finish and JobList::CallClear: CRASHLOGGER_PDB(59818@2026.10.24)
// pendingJobs and pendingProcess: GUESS(low) STANDIN
#pragma once

struct JobList {
    void Finish();
    void CallClear();
};

struct BSCullingProcess {
    static BSCullingProcess* TakePendingCullingProcess();
};

extern JobList pendingJobs;
extern BSCullingProcess* pendingProcess;
