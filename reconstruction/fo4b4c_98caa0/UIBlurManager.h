// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/U/UIBlurManager.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); counter width and helper signatures inferred from target.
#pragma once
class TESImageSpaceModifier;
class ImageSpaceModifierInstanceForm { public: static void Stop(TESImageSpaceModifier*); static void Trigger(TESImageSpaceModifier*, float, void*); };
template<class T> class BSTSingletonSDM { unsigned char singleton; };
class DefaultObjectsReadySink { public: virtual ~DefaultObjectsReadySink(); };
class UIBlurManager : public BSTSingletonSDM<UIBlurManager>, public DefaultObjectsReadySink { public: TESImageSpaceModifier* blurEffect; unsigned short blurCount; void DecrementBlurCount(); void IncrementBlurCount(); };
