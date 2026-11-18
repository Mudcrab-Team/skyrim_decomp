// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// ExtraDataList: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x173340 ExtraDataList::Function173340
// 0x172b40 ExtraDataList::Function172b40
// 0x172f60 ExtraDataList::Function172f60
// 0x16fd20 ExtraDataList::Function16fd20
#include "ExtraDataList_16fd20.h"
const char* ExtraDataList::Function173340() {
 auto data = static_cast<ExtraCellWaterEnvMap*>(GetByType(0xa6));
 if (data && data->waterEnvMap.textureName && *data->waterEnvMap.textureName) return data->waterEnvMap.textureName;
 return defaultTexture;
}
void ExtraDataList::Function172b40(void* value) {
 auto data = static_cast<ExtraAliasInstanceArray*>(GetByType(0x88));
 if (data) data->ApplyFirst(value);
}
void ExtraDataList::Function172f60(void* value) {
 auto data = static_cast<ExtraAliasInstanceArray*>(GetByType(0x88));
 if (data) data->ApplySecond(value);
}
void ExtraDataList::Function16fd20() {
 auto data = GetByType(0x57);
 if (data) RemoveData(data, true);
}
