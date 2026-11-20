// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AnimationType
#pragma once
enum class AnimationType : int {
    kUnknownAnimation = 0,
    kInterleavedAnimation = 1,
    kDeltaCompressedAnimation = 2,
    kWaveletCompressedAnimation = 3,
    kMirroredAnimation = 4,
    kSplineCompressedAnimation = 5,
    kQuantizedCompressedAnimation = 6,
};
