// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// BSParabolicCullingProcess, NiPlane, NiPoint3, NiBound, backHemisphereAccumulator, equatorialPlane, lightPosition, lightRadius: CRASHLOGGER_PDB(59818@2026.10.24)
// TestSphere, distance, side: GUESS(low) STANDIN
#pragma once

struct NiPoint3 { float x, y, z; };
struct NiPlane { NiPoint3 normal; float constant; };
struct NiBound { NiPoint3 center; float radius; };

struct BSParabolicCullingProcess {

    unsigned char unrecovered00[0x30200];
    void* backHemisphereAccumulator;
    NiPlane equatorialPlane;
    NiPoint3 lightPosition;
    float lightRadius;

    bool TestSphere(const NiBound& bound);
};
