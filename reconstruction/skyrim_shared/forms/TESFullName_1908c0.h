// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// TESFullName: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
// BaseFormComponent, TESFullName, BSFixedString, fullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// value: GUESS(low)
class BaseFormComponent {
public:
 virtual ~BaseFormComponent() {}
 virtual void InitializeDataComponent();
 virtual void ClearDataComponent();
 virtual void CopyComponent(BaseFormComponent*);
};
class BSFixedString { public: ~BSFixedString(); const char* value; };
class TESFullName : public BaseFormComponent {
public:
 ~TESFullName() override;
 BSFixedString fullName;
};
