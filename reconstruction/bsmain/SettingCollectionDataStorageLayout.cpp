// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (pinned complete public data and independent target primary RTTI/call operands).
// Code origin: public data-only adaptations; ordinary compiler deleting wrappers, complete destructor bodies external. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{S/SettingCollection.h,S/SettingCollectionList.h,I/INISettingCollection.h,I/INIPrefSettingCollection.h,R/RegSettingCollection.h,B/BSShaderProperty.h,S/ShaderReferenceEffect.h,B/BSTArray.h,B/BSSoundHandle.h}; MIT.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/BSDistantTreeShaderProperty.h; GPL-3.0.
// SettingCollection, SettingCollectionList, INISettingCollection, INIPrefSettingCollection, RegSettingCollection, BSShaderProperty, ShaderReferenceEffect, RenderPassArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSDistantTreeShaderProperty: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// New storage names, member aliases and pointee names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1558e70 represented complete settings/shader deleting wrapper
// 0x14e8580 represented complete settings/shader deleting wrapper
// 0x19ed70 represented complete settings/shader deleting wrapper
// 0x1925a0 represented complete settings/shader deleting wrapper
// 0x661ea0 represented complete settings/shader deleting wrapper
// 0x5e2100 represented complete settings/shader deleting wrapper
void operator delete(void*, unsigned __int64) noexcept;
#include "SettingCollectionDataStorageLayout.h"
static ResearchLayouts::DistantTreeShaderDataStorageLayout object0;
static ResearchLayouts::ShaderPropertyDataStorageLayout object1;
static ResearchLayouts::IniPrefSettingsDataStorageLayout object2;
static ResearchLayouts::IniSettingsDataStorageLayout object3;
static ResearchLayouts::RegistrySettingsDataStorageLayout object4;
static ResearchLayouts::ShaderReferenceDataStorageLayout object5;
