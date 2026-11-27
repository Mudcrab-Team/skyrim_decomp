// Source exposure: mixed (CrashLogger PDB names; the pinned image listing).
// Code origin: original; written from the pinned image listing with the class names labelled in the header.
// SPDX-License-Identifier: CC0-1.0
// 0xbdd230 BShkFloatController::GetRawValue
// Adapted bodies: none
#include "BShkFloatController.h"

// Reads this controller's float from the source's table, or zero when the index is out of range.
float BShkFloatController::GetRawValue(const BShkVariableSource& a_source) const
{
    const BShkFloatVariables* variables = a_source.variables;
    if (variableIndex < static_cast<std::uint32_t>(variables->numFloats)) {
        return variables->GetFloats()[variableIndex];
    }
    return 0.0f;
}
