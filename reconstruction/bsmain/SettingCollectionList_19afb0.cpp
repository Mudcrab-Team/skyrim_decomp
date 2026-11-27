// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: body adapted from the sibling function below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/BSMain/Setting.inl:85
// 0x19afb0 SettingCollectionList<Setting>::~SettingCollectionList
#include "SettingCollectionList_19afb0.h"

template <>
SettingCollectionList<Setting>::~SettingCollectionList()
{
    settings.RemoveAll(nullptr, nullptr);
}
