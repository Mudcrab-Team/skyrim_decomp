// Source exposure: mixed
// Origin: authorized sibling and community declarations
// TESForm::SetAltered: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:473
// TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESForm.h
// names: GUESS(low); scoped context and signature are provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class TESFileArray;
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent() = 0; virtual void ClearDataComponent() = 0; virtual void CopyComponent(BaseFormComponent*); };
struct TESFileContainer { TESFileArray* array; };
class TESForm : public BaseFormComponent {
public:
 void SetAltered(bool);
 TESFileContainer sourceFiles; std::uint32_t formFlags, formID; std::uint16_t inGameFormFlags; std::uint8_t formType;
};
extern __declspec(thread) std::uint32_t memoryContext;
struct MemoryScope { std::uint32_t saved; MemoryScope(): saved(memoryContext) { memoryContext = 0x59; } ~MemoryScope() { memoryContext = saved; } };
