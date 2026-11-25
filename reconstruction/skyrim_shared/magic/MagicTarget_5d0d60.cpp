// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5d0d60 MagicTarget::~MagicTarget
// Adapted bodies: none
#include "MagicTarget_5d0d60.h"

MagicTarget::~MagicTarget()
{
    while (postUpdateDispelList) {
        SpellDispelData* node = postUpdateDispelList;
        postUpdateDispelList = node->next;
        delete node;
    }
}
