// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSCompoundFrustumOperatorType
#pragma once
enum class BSCompoundFrustumOperatorType : int {
    kNone = 0,
    kStart = 1,
    kAccept = 2,
    kReject = 3,
    kGroupIntersection = 4,
    kGroupUnion = 5,
    kGroupEnd = 6,
    kTestIntersects = 7,
    kTestInside = 8,
};
