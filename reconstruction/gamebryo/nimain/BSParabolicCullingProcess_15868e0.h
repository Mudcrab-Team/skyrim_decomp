// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSParabolicCullingProcess layout, BSCullingProcess, NiPlane and NiPoint3: CRASHLOGGER_PDB(59818@2026.10.24)
// AccumulatorReference and defaultPosition: GUESS(low) STANDIN
#pragma once

struct BSCullingProcess {
    BSCullingProcess();
    virtual ~BSCullingProcess();
    unsigned char unknown08[0x301F0];
};
struct NiPoint3 {
    float x;
    float y;
    float z;
};
extern const NiPoint3 defaultPosition;
struct NiPlane {
    NiPlane();
    NiPoint3 normal;
    float constant;
};
struct BSShaderAccumulator;
struct AccumulatorReference {
    AccumulatorReference() : pointer(nullptr) {}
    ~AccumulatorReference();
    BSShaderAccumulator* pointer;
};
struct NiCamera;
struct BSParabolicCullingProcess : BSCullingProcess {
    BSParabolicCullingProcess();
    ~BSParabolicCullingProcess() override;
    float unk301F8;
    AccumulatorReference backHemisphereAccumulator;
    NiPlane equatorialPlane;
    NiPoint3 lightPosition;
    float lightRadius;
    NiCamera* lightCamera;
};
