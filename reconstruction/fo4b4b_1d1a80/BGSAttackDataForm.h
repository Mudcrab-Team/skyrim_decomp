// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSAttackDataForm::ClearDataComponent: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSAttackDataForm.cpp:21
// BGSAttackDataForm, NiRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSAttackDataForm.h, include/RE/B/BGSAttackDataMap.h, include/RE/N/NiRefObject.h and include/RE/N/NiSmartPointer.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <atomic>
class Component { public: virtual ~Component(); };
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); std::atomic<unsigned> refCount; unsigned pad; };
class BGSAttackDataMap : public NiRefObject {};
class BGSAttackDataForm : public Component { public: BGSAttackDataMap* attackDataMap; void ClearDataComponent(); };
