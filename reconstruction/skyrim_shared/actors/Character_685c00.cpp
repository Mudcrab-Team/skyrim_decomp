// Character, Point3, x, y, z, Value, Compute, Function685c00, Function68ab20, Lookup, Apply, Start, Continue, Finish: GUESS(low)
// Character::PrecacheData: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// 0x685c00 Character::Function685c00
// 0x73a9f0 Character::PrecacheData
// 0x68ab20 Character::Function68ab20

#include "Character_685c00.h"
bool Character::Function685c00(Point3* p, void*, float v) { return Compute(p->z) >= v; }
void Character::Function68ab20(void* p) { auto result = Lookup(); if (result) result->Apply(p); }
void Character::PrecacheData() { Start(); Continue(); Finish(0, 0); }
