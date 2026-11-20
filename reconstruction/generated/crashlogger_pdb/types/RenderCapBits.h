// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RenderCapBits
#pragma once
enum class RenderCapBits : int {
    kNone = 0,
    kCacheDataUse = 1,
    kIndex16 = 4,
    kIndex32 = 8,
    kRenderStats = 16,
    kRenderTargets = 32,
    kRenderTargetPrePass = 64,
    kRenderTargetNonPow2 = 128,
    kFillGouraud = 256,
    kFillGouraudTex = 512,
    kCxformAdd = 4096,
    kNestedMasks = 8192,
    kTexNonPower2 = 16384,
    kTexNonPower2Wrap = 32768,
    kCanLoseData = 65536,
    kKeepVertexData = 131072,
    kNoTexOverwrite = 262144,
    kTexNonPower2Mip = 524288,
    kThreadedTextureCreation = 1048576,
    kRenderTargetMip = 2097152,
    kFilter_Blurs = 4194304,
    kFilter_ColorMatrix = 8388608,
};
