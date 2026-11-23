// Source exposure: mixed (pinned public base declarations and independent target RTTI/table/target binding).
// Code origin: original narrowed public-data prefix composition, no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/ThirdPersonState.h,T/TESObjectCELL.h,T/TESCameraState.h,P/PlayerInputHandler.h,T/TESForm.h,T/TESFullName.h}; MIT.
// ThirdPersonState, TESObjectCELL, TESCameraState, PlayerInputHandler, TESForm, TESFullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ThirdPersonInputPrefixLayout, CellFullNamePrefixLayout and mirror names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include "../../bssystem/QueuedFileDataStorageLayout.h"
namespace ResearchLayouts {
class ThirdPersonInputPrefixLayout : public CameraStateDataStorageLayout, public PlayerInputDataStorageLayout {
public:
    ThirdPersonInputPrefixLayout();
    ~ThirdPersonInputPrefixLayout() override;
};
class CellFullNamePrefixLayout : public FormHeaderLayout, public FullNameComponentLayout {
public:
    CellFullNamePrefixLayout();
    ~CellFullNamePrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
struct ThirdPersonInputPrefixMirrorLayout { CameraStateDataStorageLayout state;PlayerInputDataStorageLayout input; };
struct CellFullNamePrefixMirrorLayout { FormHeaderLayout form;FullNameComponentLayout name; };
static_assert(sizeof(ThirdPersonInputPrefixLayout)==48,"initial public camera/input bases only");
static_assert(sizeof(CellFullNamePrefixLayout)==48,"initial public form/name bases only");
static_assert(sizeof(ThirdPersonInputPrefixMirrorLayout)==48,"physical camera prefix mirror");
static_assert(sizeof(CellFullNamePrefixMirrorLayout)==48,"physical cell prefix mirror");
static_assert(offsetof(ThirdPersonInputPrefixMirrorLayout,state)==0,"public primary camera base");
static_assert(offsetof(ThirdPersonInputPrefixMirrorLayout,input)==32,"public and independent target input base");
static_assert(offsetof(CellFullNamePrefixMirrorLayout,form)==0,"public primary form base");
static_assert(offsetof(CellFullNamePrefixMirrorLayout,name)==32,"public and independent target full-name base");
}
