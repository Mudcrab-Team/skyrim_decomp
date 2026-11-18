// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/A/ActiveEffectReferenceEffectController.h and RE/R/ReferenceEffectController.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); save buffer helper inferred from target.
#pragma once
class ActiveEffect; class BGSSaveGameBuffer { public: void SaveFormID(unsigned int*, bool); };
class ReferenceEffectController { public: virtual ~ReferenceEffectController(); };
class ActiveEffectReferenceEffectController: public ReferenceEffectController { public: ActiveEffect* effect; unsigned int target; void SaveGame(BGSSaveGameBuffer*) const; };
