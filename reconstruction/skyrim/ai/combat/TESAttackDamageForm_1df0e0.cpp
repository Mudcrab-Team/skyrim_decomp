// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// TESAttackDamageForm::CopyComponent: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESAttackDamageForm.cpp:33
// TESAttackDamageForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/T/TESAttackDamageForm.h and include/RE/B/BaseFormComponent.h.
// names: GUESS(low); argument name and call interpretation are inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1df0e0 TESAttackDamageForm::CopyComponent
#include "TESAttackDamageForm_1df0e0.h"
void TESAttackDamageForm::CopyComponent(BaseFormComponent* source) { auto* damage = dynamic_cast<TESAttackDamageForm*>(source); if (damage) attackDamage = damage->GetAttackDamage(); }
