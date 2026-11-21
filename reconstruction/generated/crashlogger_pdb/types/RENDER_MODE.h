// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RENDER_MODE
#pragma once
enum class RENDER_MODE : int {
    kNormal = 0,
    kShadowMask = 12,
    kShadowMapPlain = 13,
    kShadowMapClamped = 14,
    kShadowMapPb = 15,
    kShadowMapCube = 17,
    kLocalMap = 18,
    kLodLandscapePass = 20,
    kWaterReflectionPass = 21,
    kBloodDecalPass = 22,
    kAlphaTransparencyShadowPass = 23,
    kSunGlintRefractionPass = 24,
    kVolumetricLightingPass = 25,
    kOcclusion = 26,
    kPrecipitationOcclusionMap = 28,
};
