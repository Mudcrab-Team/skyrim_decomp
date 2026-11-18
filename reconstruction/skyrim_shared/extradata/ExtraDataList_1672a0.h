// ExtraDataList, ObjectRefHandle: GUESS(low) STANDIN
// Origin: original reconstruction; partial declarations adapt CommonLibSSE-NG, MIT.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSPointerHandle.h, include/RE/E/ExtraAshPileRef.h, include/RE/E/ExtraDataList.h.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// ObjectRefHandle, BSExtraData, ExtraAshPileRef, ExtraOpenCloseActivateRef, ExtraDataList, GetAshPileRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// GetOpenCloseActivateRef: GUESS(low)
// GetByType, value, next, ashPileRef, activateRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ObjectRefHandle {
public:
  ObjectRefHandle() noexcept = default;
  ObjectRefHandle(const ObjectRefHandle&) noexcept = default;
  ~ObjectRefHandle() noexcept { value = 0; }
  std::uint32_t value{0};
};
class BSExtraData { public: virtual ~BSExtraData() = default; BSExtraData* next; };
class ExtraAshPileRef : public BSExtraData { public: ObjectRefHandle ashPileRef; };
class ExtraOpenCloseActivateRef : public BSExtraData { public: ObjectRefHandle activateRef; };
class ExtraDataList {
public:
  BSExtraData* GetByType(std::uint32_t type);
  ObjectRefHandle& GetAshPileRef(ObjectRefHandle& result);
  ObjectRefHandle& GetOpenCloseActivateRef(ObjectRefHandle& result);
};
