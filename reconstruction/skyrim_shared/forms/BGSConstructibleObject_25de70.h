// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSConstructibleObject::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/BGSConstructibleObject.cpp:109
// BGSConstructibleObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSConstructibleObject.h, include/RE/T/TESForm.h, include/RE/T/TESContainer.h and include/RE/T/TESCondition.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct FileContainer { void* array; };
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent(); };
class TESForm : public BaseFormComponent { public: FileContainer sourceFiles; unsigned formFlags, formID; unsigned short inGameFlags; unsigned char formType, pad; unsigned pad2; };
class TESContainer : public BaseFormComponent { public: void** containerObjects; unsigned numContainerObjects; };
struct TESCondition { void* head; };
class BGSConstructibleObject : public TESForm { public: TESContainer requiredItems; TESCondition conditions; TESForm* createdItem; void* benchKeyword; void InitializeData(); };
