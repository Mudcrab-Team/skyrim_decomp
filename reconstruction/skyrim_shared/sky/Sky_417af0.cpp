// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Sky: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x417af0 Sky::Function417af0
#include "Sky_417af0.h"
void Sky::Function417af0() {
 if (!skySoundList) return;
 auto* node = &skySoundList->_listHead;
 while (node && node->item) {
  UpdateSound(node->item);
  node = node->next;
 }
}
