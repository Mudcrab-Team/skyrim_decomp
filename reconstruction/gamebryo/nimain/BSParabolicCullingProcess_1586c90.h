// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// BSParabolicCullingProcess, UpdateLightPlanes, NiCamera, NiPlane, NiPoint3, camera, lightCamera, lightPosition, lightRadius, activePlanes, equatorialPlane, refCount: CRASHLOGGER_PDB(59818@2026.10.24)
// worldRotation, worldTranslation, SetNormalAndPoint: GUESS(low) STANDIN
#pragma once

struct NiPoint3 {
    float x, y, z;
    NiPoint3& operator=(const NiPoint3& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};
struct NiPlane { NiPoint3 normal; float constant; NiPlane(const NiPoint3& normal, const NiPoint3& point); };
struct NiBound { NiPoint3 center; float radius; };

struct NiCamera {
    unsigned char unrecovered00[8];
    long refCount;
    unsigned char unrecovered0C[0x70];
    float worldRotation[3][3];
    NiPoint3 worldTranslation;
};
struct BSParabolicCullingProcess {
    unsigned char unrecovered00[0x18];
    NiCamera* camera;
    unsigned char unrecovered20[0x7C];
    unsigned int activePlanes;
    unsigned char unrecoveredA0[0x301F8 - 0xA0];
    float unk301F8;
    unsigned char unrecovered1FC[12];
    NiPlane equatorialPlane;
    NiPoint3 lightPosition;
    float lightRadius;
    NiCamera* lightCamera;
    void UpdateLightPlanes(NiCamera* newCamera, float radius, bool rememberCamera);
};
