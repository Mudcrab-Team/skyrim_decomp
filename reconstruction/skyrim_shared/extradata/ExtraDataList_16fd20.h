// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// ExtraDataList: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// BSExtraData, ExtraAliasInstanceArray, ExtraCellWaterEnvMap, TESTexture, ExtraDataList, GetByType, next, waterEnvMap, textureName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function173340, Function172b40, Function172f60, Function16fd20, ApplyFirst, ApplySecond, RemoveData, defaultTexture: GUESS(low)
class BSExtraData { public: virtual ~BSExtraData() = default; BSExtraData* next; };
class TESTexture { public: virtual ~TESTexture() = default; const char* textureName; };
class ExtraCellWaterEnvMap : public BSExtraData { public: TESTexture waterEnvMap; };
class ExtraAliasInstanceArray : public BSExtraData { public: void ApplyFirst(void*); void ApplySecond(void*); };
extern const char* defaultTexture;
class ExtraDataList {
public:
 BSExtraData* GetByType(std::uint32_t);
 void RemoveData(BSExtraData*, bool);
 const char* Function173340();
 void Function172b40(void*);
 void Function172f60(void*);
 void Function16fd20();
};
