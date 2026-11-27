// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis).
// Code origin: Stamped as a twin of matched 0xbc19d0 (gamebryo/nianimation/BSAnimationGraphManager_bc19d0): source copied, names replaced by placeholders.
// 0xceb3d0 Ownerceb3d0::Functionceb3d0
#include "Ownerceb3d0.h"

// guess: same compiled code as matched 0xbc19d0 apart from relocated fields; its role here is not established.
void Ownerceb3d0::Functionceb3d0() { if (singleton) { singleton->~Ownerceb3d0(); singleton = nullptr; } }
