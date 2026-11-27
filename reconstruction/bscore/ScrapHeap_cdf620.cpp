// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction with the declared community destructor adaptation.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: ScrapHeap::~ScrapHeap, CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/S/ScrapHeap.h:43 (MIT).
// 0xcdf620 ScrapHeap::~ScrapHeap
#include "ScrapHeap_cdf620.h"

ScrapHeap::~ScrapHeap()
{
    VirtualFree(baseAddress, 0, 0x8000);
}
