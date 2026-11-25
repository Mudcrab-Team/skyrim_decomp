// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSWin32TaskletManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionec5980: GUESS(low); provisional member name
// 0xec5980 BSWin32TaskletManager::Functionec5980
// CI hash: 0xec5980 ?Functionec5980@BSWin32TaskletManager@@QEAAXXZ
#include "BSWin32TaskletManager_ec5980.h"

// Guess: Finish the task manager state and terminate its worker thread.
void BSWin32TaskletManager::Functionec5980()
{
    state.Finish();
    Stop();
    ExitTaskThread(0);
}
