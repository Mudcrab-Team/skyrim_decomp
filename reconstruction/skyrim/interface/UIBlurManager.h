// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// UIBlurManager, BSTSingletonSDM, TESImageSpaceModifier, ImageSpaceModifierInstanceForm, blurEffect, blurCount, DecrementBlurCount, IncrementBlurCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// DefaultObjectsReadySink, g_uiBlurManagerInstance, Function98cad0, Function98cae0, Function98cb00: GUESS(low)
#pragma once
class TESImageSpaceModifier;
class ImageSpaceModifierInstanceForm { public: static void Stop(TESImageSpaceModifier*); static void Trigger(TESImageSpaceModifier*, float, void*); };
template<class T> class BSTSingletonSDM { unsigned char singleton; };
class DefaultObjectsReadySink { public: virtual ~DefaultObjectsReadySink(); };
class UIBlurManager;
extern UIBlurManager* g_uiBlurManagerInstance;
class UIBlurManager : public BSTSingletonSDM<UIBlurManager>, public DefaultObjectsReadySink {
public:
    TESImageSpaceModifier* blurEffect;
    unsigned short blurCount;
    void DecrementBlurCount();
    void IncrementBlurCount();
    void Function98cad0();
    void Function98cae0();
    void Function98cb00();
};
