// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// TESAttackDamageForm::CopyComponent: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESAttackDamageForm.cpp:33
// TESAttackDamageForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/T/TESAttackDamageForm.h and include/RE/B/BaseFormComponent.h.
// names: GUESS(low); argument name and call interpretation are inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent(); virtual void ClearDataComponent(); virtual void CopyComponent(BaseFormComponent*); };
class TESAttackDamageForm : public BaseFormComponent { public: void CopyComponent(BaseFormComponent*) override; virtual std::uint16_t GetAttackDamage() const; std::uint16_t attackDamage; };
