// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSProjectileData; size 0x88
#pragma once

struct BGSCollisionLayer;
struct BGSExplosion;
struct BGSSoundDescriptorForm_de361764;
struct BGSTextureSet_d8b0e61f;
struct TESObjectLIGH;
struct TESObjectWEAP;
struct BGSProjectileData {
    unsigned short flags;  // BGSProjectileFlags in the PDB is wider than this slot
    unsigned short types;  // Type in the PDB is wider than this slot
    float gravity;
    float speed;
    float range;
    TESObjectLIGH* light;
    TESObjectLIGH* muzzleFlashLight;
    float tracerChance;
    float explosionProximity;
    float explosionTimer;
    unsigned int pad2C;
    BGSExplosion* explosionType;
    BGSSoundDescriptorForm_de361764* activeSoundLoop;
    float muzzleFlashDuration;
    float fadeOutTime;
    float force;
    unsigned int pad4C;
    BGSSoundDescriptorForm_de361764* countdownSound;
    BGSSoundDescriptorForm_de361764* deactivateSound;
    TESObjectWEAP* defaultWeaponSource;
    float coneSpread;
    float collisionRadius;
    float lifetime;
    float relaunchInterval;
    BGSTextureSet_d8b0e61f* decalData;
    BGSCollisionLayer* collisionLayer;
};
static_assert(sizeof(BGSProjectileData) == 136, "BGSProjectileData layout differs from the PDB");
