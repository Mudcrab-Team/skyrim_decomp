// Code origin: original; hand-written reconstruction from local binary analysis and labelled declarations.
// 0x11e22c0 BSNavmesh::GetGridBounds
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh, BSNavmeshGrid, NiPoint3, meshGrid, gridSize, columnSectionLen, rowSectionLen, gridBoundsMin, gridBoundsMax, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetGridBounds: GUESS(low); copies bounds and reports initialized grid state.
// unk00, unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50, unk58, unk60, unk68, unk70, unk78, unk80, unk88, unk90, unk98: GUESS(low); unaccessed storage.
// Recipe: reconstruction/recipes/o2-fpfast.json
// Cookbook: 48
#include "BSNavmesh_11e22c0.h"
#include <cfloat>

bool BSNavmesh::GetGridBounds(NiPoint3* minimum, NiPoint3* maximum) const
{
    *minimum = meshGrid.gridBoundsMin;
    *maximum = meshGrid.gridBoundsMax;
    return meshGrid.gridSize != 0 || meshGrid.gridBoundsMin.x != FLT_MAX;
}
