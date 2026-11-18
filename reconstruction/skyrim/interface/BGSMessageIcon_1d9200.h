// Adapted declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); paths listed below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Field names and declarations: GUESS; calls and offsets corroborated by target.
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
class BSString; class BSFixedString { const char* data; };
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent()=0; virtual void ClearDataComponent()=0; virtual void CopyComponent(BaseFormComponent*); };
class TESTexture: public BaseFormComponent { public: void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual std::uint32_t GetMaxAllowedSize(); virtual const char* GetAsNormalFile(BSString&) const; virtual const char* GetDefaultPath() const; BSFixedString textureName; };
class TESIcon: public TESTexture { public: const char* GetDefaultPath() const override; };
class BGSMessageIcon: public BaseFormComponent { public: void InitializeDataComponent() override; void ClearDataComponent() override; TESIcon icon; };
