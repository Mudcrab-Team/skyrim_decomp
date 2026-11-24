// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis).
// Code origin: Stamped as a twin of matched 0xbc19d0 (gamebryo/nianimation/BSAnimationGraphManager_bc19d0): source copied, names replaced by placeholders.
// 0x63bfd0 Owner63bfd0::Function63bfd0
#include "Owner63bfd0.h"

// guess: same compiled code as matched 0xbc19d0 apart from relocated fields; its role here is not established.
void Owner63bfd0::Function63bfd0() { if (singleton) { singleton->~Owner63bfd0(); singleton = nullptr; } }
