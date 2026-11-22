// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: SKELETON_TODO_CODE_ORIGIN (state the actual origin and any adaptation)
// SPDX-License-Identifier: CC0-1.0
// 0xff3380 BSMultiBoundNode::Functionff3380
// Adapted bodies: SKELETON_TODO_ORIGIN (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; these bodies reconstructed from the pinned image listing (IsEqual from the existing unit)
// SPDX-License-Identifier: CC0-1.0
// 0xff3470 BSMultiBoundNode::Functionff3470
// Adapted bodies: none
// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; these bodies reconstructed from the pinned image listing (IsEqual from the existing unit)
// SPDX-License-Identifier: CC0-1.0
// 0xff3430 BSMultiBoundNode::Functionff3430
// 0xff3450 BSMultiBoundNode::Functionff3450
// 0xff3470 BSMultiBoundNode::Functionff3470
// Adapted bodies: none
// Code origin: body written by the contributor from the compared function's behaviour; names and
// declarations come from the header (CharmedBaryon/CommonLibSSE-NG, MIT).
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
#include "BSMultiBoundNode.h"

extern void Helperff3380();

void BSMultiBoundNode::Functionff3380()
{
    Helperff3380();
    UpdateWorldBound();
}

void* BSMultiBoundNode::Functionff3430()
{
    return multiBound->b37();
}

void BSMultiBoundNode::Functionff3450()
{
    multiBound->inner->i40();
}

void BSMultiBoundNode::Functionff3470()
{
    multiBound->inner->i39();
}


bool BSMultiBoundNode::IsEqual(NiObject* a_object)
{
    BSNiNode::IsEqual(a_object);
    return multiBound == static_cast<BSMultiBoundNode*>(a_object)->multiBound;
}
