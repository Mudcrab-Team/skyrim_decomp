// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSTaskletManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionec3aa0: GUESS(low); provisional member name
// 0xec3aa0 BSTaskletManager::Functionec3aa0
// CI hash: 0xec3aa0 ?Functionec3aa0@BSTaskletManager@@QEAAXAEAPEAUTaskEc3aa0@@_N@Z
#include "BSTaskletManager_ec3aa0.h"

// Guess: Prepare and execute a tasklet before submitting and clearing it.
void BSTaskletManager::Functionec3aa0(TaskEc3aa0*& task, bool mode)
{
    if (task) {
        task->Prepare();
        if (task && !task->cancelled) { task->Run(mode); }
        Submit(task);
        task = nullptr;
    }
}
