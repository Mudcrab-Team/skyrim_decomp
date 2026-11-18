// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// IMovementPlannerDirectControl::~IMovementPlannerDirectControl: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/IMovementPlannerDirectControl.h:6
// IMovementPlannerDirectControl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/I/IMovementPlannerDirectControl.h, include/RE/I/IMovementInterface.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class IMovementInterface { public: virtual ~IMovementInterface(); };
class IMovementPlannerDirectControl : public IMovementInterface { public: ~IMovementPlannerDirectControl() override; virtual void Unk01() = 0; virtual void Unk02() = 0; virtual void Unk03() = 0; virtual void Unk04() = 0; virtual void Unk05() = 0; };
