// ExtraDataList, ObjectRefHandle: GUESS(low) STANDIN
// Origin: original reconstruction; partial declarations adapt CommonLibSSE-NG, MIT.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSPointerHandle.h, include/RE/E/ExtraAshPileRef.h, include/RE/E/ExtraDataList.h.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1672a0 ExtraDataList::GetAshPileRef
// 0x169130 ExtraDataList::GetOpenCloseActivateRef
#include "ExtraDataList.h"
ObjectRefHandle& ExtraDataList::GetAshPileRef(ObjectRefHandle& result) {
  result.value = 0;
  auto data = static_cast<ExtraAshPileRef*>(GetByType(0x85));
  if (data) result = data->ashPileRef;
  return result;
}
ObjectRefHandle& ExtraDataList::GetOpenCloseActivateRef(ObjectRefHandle& result) {
  result.value = 0;
  auto data = static_cast<ExtraOpenCloseActivateRef*>(GetByType(0x68));
  if (data) result = data->activateRef;
  return result;
}
