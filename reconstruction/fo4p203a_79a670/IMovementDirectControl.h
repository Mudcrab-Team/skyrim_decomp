// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// IMovementDirectControl::~IMovementDirectControl: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/IMovementDirectControl.h:6
// IMovementDirectControl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/I/IMovementDirectControl.h, include/RE/I/IMovementInterface.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class IMovementInterface { public: virtual ~IMovementInterface(); };
class IMovementDirectControl : public IMovementInterface { public: ~IMovementDirectControl() override; virtual void Unk01() = 0; virtual void Unk02() = 0; virtual void Unk03() = 0; virtual void Unk04() = 0; virtual void Unk05() = 0; virtual void Unk06() = 0; virtual void Unk07() = 0; virtual void Unk08() = 0; };
