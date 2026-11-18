// Inferred names: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction informed by CommonLibSSE-NG declarations (MIT).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BGSHeadPart: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)

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
// BaseFormComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
// BSFixedString, _data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct BSFixedString { const char* _data; };
// TESFileContainer, array: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESFileArray;
struct TESFileContainer { TESFileArray* array; };
// TESForm, sourceFiles, formFlags, formID, inGameFormFlags, formType, pad1B, pad1C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESForm : public BaseFormComponent { public: TESFileContainer sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
// TESFullName, fullName: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESFullName : public BaseFormComponent { public: BSFixedString fullName; };
// TESModel, model, textures, addons, numTextures, numAddons, pad24: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
namespace BSResource { struct ID; }
class TESModel : public BaseFormComponent { public: BSFixedString model; BSResource::ID* textures; std::uint32_t* addons; std::uint16_t numTextures; std::uint16_t numAddons; std::uint32_t pad24; };
// TESModelTextureSwap, AlternateTexture, alternateTextures, numAlternateTextures, pad34: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESModelTextureSwap : public TESModel { public: struct AlternateTexture; AlternateTexture* alternateTextures; std::uint32_t numAlternateTextures; std::uint32_t pad34; };
// TESModelTri: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESModelTri : public TESModel {};
// BSTArrayHeapAllocator, _data, _capacity, BSTArrayBase, _size, BSTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct BSTArrayHeapAllocator { void* _data; std::uint32_t _capacity; };
struct BSTArrayBase { std::uint32_t _size; };
template<class T> struct BSTArray : BSTArrayHeapAllocator, BSTArrayBase {};
// BGSListForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Query: GUESS(low)
class BGSListForm { public: std::int32_t Query(); };
class BGSTextureSet; class BGSColorForm;
// BGSHeadPart, flags, type, extraParts, textureSet, morphs, color, validRaces: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// sub: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class BGSHeadPart : public TESForm, public TESFullName, public TESModelTextureSwap { public:
 bool sub(); std::uint8_t flags; std::uint8_t pad069; std::uint16_t pad06A; std::uint32_t type; BSTArray<BGSHeadPart*> extraParts; BGSTextureSet* textureSet; TESModelTri morphs[3]; BGSColorForm* color; BGSListForm* validRaces;
};
