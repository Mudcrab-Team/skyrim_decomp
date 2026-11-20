// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PixelLayout
#pragma once
enum class PixelLayout : int {
    kPalettized8 = 0,
    kHighColor16 = 1,
    kTrueColor32 = 2,
    kCompressed = 3,
    kBumpmap = 4,
    kPalettized4 = 5,
    kDefault = 6,
    kSingleColor8 = 7,
    kSingleColor16 = 8,
    kSingleColor32 = 9,
    kDoubleColor32 = 10,
    kDoubleColor64 = 11,
    kFloatColor32 = 12,
    kFloatColor64 = 13,
    kFloatColor128 = 14,
};
