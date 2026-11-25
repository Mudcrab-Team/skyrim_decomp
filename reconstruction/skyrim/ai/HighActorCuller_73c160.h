// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// HighActorCuller, MobIterOperator, BSFadeNodeCuller, NiCullingProcess and HighActorCuller member layout: CRASHLOGGER_PDB(59818@2026.10.24)
// partial base-class declarations and processType width: GUESS(low) STANDIN
#pragma once

struct NiCullingProcess {
    explicit NiCullingProcess(void* visibleSet);
    virtual ~NiCullingProcess();
    unsigned char unknown08[0x120];
};
struct BSFadeNodeCuller : NiCullingProcess {
    BSFadeNodeCuller() : NiCullingProcess(nullptr) {}
    ~BSFadeNodeCuller() override;
};
struct MobIterOperator {
    virtual ~MobIterOperator() {}
    unsigned int processType;
    MobIterOperator() : processType(0) {}
};
struct HighActorCuller : MobIterOperator {
    HighActorCuller();
    ~HighActorCuller() override;
    BSFadeNodeCuller culler;
    void* multiBoundNode;
    void* multiBound;
    void* multiBoundSphere;
};
