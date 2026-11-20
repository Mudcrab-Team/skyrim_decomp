// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CollisionDetail; size 0x10
#pragma once

struct hkpCollidable_9bd4f602;
struct hkpCollisionAgent_376ce446;
struct CollisionDetail {
    hkpCollisionAgent_376ce446* agent;
    hkpCollidable_9bd4f602* collidable;
};
static_assert(sizeof(CollisionDetail) == 16, "CollisionDetail layout differs from the PDB");
