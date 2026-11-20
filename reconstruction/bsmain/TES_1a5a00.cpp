// TES, Function1a5a00, Function1a5a30, FindCell, Cell, GetValueA, GetValueB, fallback: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// 0x1a5a00 TES::Function1a5a00
// 0x1a5a30 TES::Function1a5a30

#include "TES_1a5a00.h"
float TES::Function1a5a00() { auto cell = FindCell(); return cell ? cell->GetValueA() : fallback; }
float TES::Function1a5a30() { auto cell = FindCell(); return cell ? cell->GetValueB() : fallback; }
