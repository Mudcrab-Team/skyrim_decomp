// 0xffdd10 BSProceduralLightningController::GetPropertyHolder
// Code origin: original reconstruction from pinned-image observations; declarations use the labelled sources.
// Source exposure: mixed
// GetPropertyHolder: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSProceduralLightningController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiNode, BSGeometry, AsNode, AsGeometry, NiTimeController::target, children, NiTArray::_data, NiTArray::_freeIdx: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiChildArray: STANDIN GUESS(low); minimal child-array view
#include "BSProceduralLightningController_ffdd10.h"

// Return the first child geometry when the controller targets a populated node.
BSGeometry* BSProceduralLightningController::GetPropertyHolder() const
{
    if (target) {
        NiNode* node = target->AsNode();
        if (node && node->children._freeIdx > 0) {
            NiObject* child = node->children._data[0];
            if (child) {
                return child->AsGeometry();
            }
        }
    }
    return nullptr;
}
