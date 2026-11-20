// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// TESBipedModelForm, BaseFormComponent, TESModel, TESModelTextureSwap, TESModelRDT, TESTexture, TESIcon, BGSMessageIcon, worldModels, inventoryIcons, messageIcons, constraintTemplate: GUESS(low); target calls corroborate selected offsets and slots.
/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#pragma once
#include <cstdint>
class BSFixedString { const char* data; }; class BSString;
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent()=0; virtual void ClearDataComponent()=0; virtual void CopyComponent(BaseFormComponent*); };
class TESModelTextureSwap; class TESModel: public BaseFormComponent { public: void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual const char* GetModel() const; virtual void SetModel(const char*); virtual TESModelTextureSwap* GetAsModelTextureSwap(); BSFixedString model; void* textures; std::uint32_t* addons; std::uint16_t numTextures; std::uint16_t numAddons; };
class TESModelTextureSwap: public TESModel { public: struct AlternateTexture; void InitializeDataComponent() override; void ClearDataComponent() override; AlternateTexture* alternateTextures; std::uint32_t numAlternateTextures; };
class TESModelRDT: public TESModel {};
class TESTexture: public BaseFormComponent { public: void InitializeDataComponent() override; void ClearDataComponent() override; BSFixedString textureName; }; class TESIcon: public TESTexture {}; class BGSMessageIcon: public BaseFormComponent { public: void InitializeDataComponent() override; void ClearDataComponent() override; TESIcon icon; };
class TESBipedModelForm: public BaseFormComponent { public: void InitializeDataComponent() override; void ClearDataComponent() override; TESModelTextureSwap worldModels[2]; TESIcon inventoryIcons[2]; BGSMessageIcon messageIcons[2]; TESModelRDT constraintTemplate; };
