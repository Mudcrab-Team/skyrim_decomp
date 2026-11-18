// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/B/BGSShaderParticleGeometryData.h, include/RE/B/BSTArray.h and include/RE/T/TESForm.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); target callees and signatures are inferred independently from the target call sequence.
#pragma once
class TESFileArray; class BaseFormComponent { public: virtual ~BaseFormComponent(); }; class TESForm : public BaseFormComponent { public: TESFileArray* sourceFiles; unsigned formFlags, formID; unsigned short inGameFormFlags; unsigned char formType; unsigned char pad1B; unsigned pad1C; };
union SettingValue { float f; unsigned i; };
class SettingArray { public: SettingValue* data; unsigned capacity; unsigned allocatorState; unsigned size; void DestroyElements(); void Clear() { if (data) { DestroyElements(); size = 0; } } };
class BGSShaderParticleGeometryData : public TESForm { public: SettingArray data; void ClearData(); };
