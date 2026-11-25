// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// HighActorCuller layout, NiCamera::viewFrustum and NiCullingProcess::SetFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorVisibilityProcess, InitializeBounds, Update, ActorManager and Visit: GUESS(low) STANDIN
#pragma once

#include "generated/crashlogger_pdb/types/NiFrustum.h"

struct NiCamera {
    unsigned char unknown00[0x150];
    NiFrustum viewFrustum;
};
struct ActorVisibilityProcess {
    unsigned char unknown00[0x18];
    NiCamera* camera;
    unsigned char unknown20[0x108];
    void SetFrustum(const NiFrustum& frustum);
};
struct HighActorCuller {
    unsigned char unknown00[0x10];
    ActorVisibilityProcess culler;
    void* multiBoundNode;
    void* multiBound;
    void* multiBoundSphere;
    void InitializeBounds(NiCamera* camera);
    void Update(NiCamera* camera);
};
struct ActorManager {
    void Visit(HighActorCuller* culler);
};
extern ActorManager* actorManager;
