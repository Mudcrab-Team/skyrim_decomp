// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSProjectileFlags
#pragma once
enum class BGSProjectileFlags : int {
    kNone = 0,
    kHitScan = 1,
    kExplosion = 2,
    kExplosionAltTrigger = 4,
    kMuzzleFlash = 8,
    kCanTurnOff = 32,
    kCanPickUp = 64,
    kSupersonic = 128,
    kPinsLimbs = 256,
    kPassSMTransparent = 512,
    kDisableCombatAimCorrection = 1024,
    kContinuousUpdate = 2048,
};
