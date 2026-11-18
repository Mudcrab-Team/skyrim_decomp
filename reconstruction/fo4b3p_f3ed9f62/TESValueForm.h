// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// TESValueForm, TESForm, BaseFormComponent, value, AddChange: GUESS(low); field and dispatch slot corroborated by target.
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
class TESFile; class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent()=0; virtual void ClearDataComponent()=0; virtual void CopyComponent(BaseFormComponent*); }; class TESForm: public BaseFormComponent { public: virtual void InitializeData(); virtual void ClearData(); virtual bool Load(TESFile*); virtual bool LoadPartial(TESFile*); virtual bool LoadEdit(TESFile*); virtual TESForm* CreateDuplicateForm(bool,void*); virtual bool AddChange(std::uint32_t); }; class TESValueForm: public BaseFormComponent { public: void CopyComponent(BaseFormComponent*) override; std::int32_t value; };
