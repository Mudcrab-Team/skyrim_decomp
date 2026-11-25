// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and published community declarations).
// Factory types and template arguments: EXE_RTTI
// Destructor slot and size: OBSERVED
// Virtual declarations and _name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnregisterFormFactory and integral argument types: GUESS(low) STANDIN
// Code origin: original form-factory destructor template. Adapted bodies: none.
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

class TESForm;

class IFormFactory
{
public:
    virtual ~IFormFactory() {}
    virtual TESForm* CreateImpl() = 0;
    virtual const char* GetFormName() const = 0;
    virtual unsigned char GetFormType() const = 0;
    virtual const char* GetObjectName() const;
    virtual unsigned int GetObjectType() const;
    virtual unsigned int GetObjectCategory() const;

    static void UnregisterFormFactory(unsigned char formType);
};
