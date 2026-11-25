// Release, manager, material: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Code origin: Stamped as a twin of matched 0x15758c0 (bsshader/BSShaderMaterial_15758c0): source copied, names replaced by placeholders.
// 0x1524a30 Owner1524a30::Function1524a30
#include "Owner1524a30.h"

// guess: same compiled code as matched 0x15758c0 apart from relocated fields; its role here is not established.
void Owner1524a30::Function1524a30() { manager->Release(material); material = nullptr; }
