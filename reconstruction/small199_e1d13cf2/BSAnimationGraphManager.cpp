// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis).
// BSAnimationGraphManager: EXE_RTTI
// 0xbc19d0 BSAnimationGraphManager::Functionbc19d0

#include "BSAnimationGraphManager.h"
void BSAnimationGraphManager::Functionbc19d0() { if (singleton) { singleton->~BSAnimationGraphManager(); singleton = nullptr; } }
