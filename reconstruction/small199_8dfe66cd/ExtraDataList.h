// Inferred names: GUESS(low)
// Origin: original reconstruction informed by CommonLibSSE-NG declarations (MIT).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// ExtraDataList: GUESS(low)

// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <cstdint>

// BSExtraData, next, ExtraHotkey, ExtraLevCreaModifier, ExtraNorthRotation, ExtraFavorCost, ExtraHealth, ExtraTimeLeft, ExtraCharge, ExtraCachedScale, ExtraScale, ExtraObjectHealth, ExtraHeadTrackingWeight, ExtraAction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSExtraData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
// hotkey: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraHotkey : public BSExtraData { public: std::uint8_t hotkey; };
// modifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraLevCreaModifier : public BSExtraData { public: std::uint32_t modifier; };
// northRot: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraNorthRotation : public BSExtraData { public: float northRot; };
// cost: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraFavorCost : public BSExtraData { public: float cost; };
// health: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraHealth : public BSExtraData { public: float health; };
// time: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraTimeLeft : public BSExtraData { public: float time; };
// charge: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraCharge : public BSExtraData { public: float charge; };
// scale3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraCachedScale : public BSExtraData { public: float scale3D; float refScale; };
// scale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraScale : public BSExtraData { public: float scale; };
// health: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraObjectHealth : public BSExtraData { public: float health; };
// weight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraHeadTrackingWeight : public BSExtraData { public: float weight; };
// action: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraAction : public BSExtraData { public: std::int8_t action; };
// ExtraDataList, GetByType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ExtraDataList { public:
  BSExtraData* GetByType(std::uint32_t type);
  // Function163960: GUESS(low)
  std::uint8_t Function163960();
  // Function1693b0: GUESS(low)
  std::uint32_t Function1693b0();
  // Function16e440: GUESS(low)
  float Function16e440();
  // Function171e60: GUESS(low)
  float Function171e60();
  // GetTemper: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
  float GetTemper();
  // Function164920: GUESS(low)
  float Function164920();
  // GetCharge: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
  float GetCharge();
  // Function1649b0: GUESS(low)
  float Function1649b0();
  // Function1649e0: GUESS(low)
  float Function1649e0();
  // Function164a10: GUESS(low)
  float Function164a10();
  // Function170dc0: GUESS(low)
  float Function170dc0();
  // Function171cf0: GUESS(low)
  float Function171cf0();
};
// defaultA, defaultB: GUESS(low) STANDIN
extern float defaultA;
extern float defaultB;
