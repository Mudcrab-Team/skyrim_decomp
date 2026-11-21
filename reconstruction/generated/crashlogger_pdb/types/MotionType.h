// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MotionType
#pragma once
enum class MotionType : int {
    kInvalid = 0,
    kDynamic = 1,
    kSphereInertia = 2,
    kBoxInertia = 3,
    kKeyframed = 4,
    kFixed = 5,
    kThinBoxInertia = 6,
    kCharacter = 7,
    kTotal = 8,
};
