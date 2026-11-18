// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// BGSPackageDataLocationWrapper::AllocateLocation: SIBLING(fo4-private@1b765c70, author-permission); adapted location cloning.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageData.cpp:159
// IAIWorldLocationHandle, IPackageDataAIWorldLocationHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x44e3c0 BGSPackageDataLocationWrapper::AllocateLocation
#include "BGSPackageDataLocationWrapper_44e3c0.h"
const IAIWorldLocation* BGSPackageDataLocationWrapper::AllocateLocation(AIWorldLocationContext&) const {
    return location->Clone();
}
