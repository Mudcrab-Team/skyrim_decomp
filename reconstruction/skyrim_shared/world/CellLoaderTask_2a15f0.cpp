// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0x2a15f0 CellLoaderTask::GetDescription
#include "CellLoaderTask_2a15f0.h"
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool CellLoaderTask::GetDescription(char* a_buf, std::uint32_t a_size)
{
    if (hasCell) {
        std::uint32_t id = cell->formID;
        const char* name = cell->GetEditorID();
        FormatDescription(a_buf, a_size, gCellFormFormat, name, id);
    } else {
        FormatDescription(a_buf, a_size, gCellCoordFormat, coordX, coordY);
    }
    return true;
}
