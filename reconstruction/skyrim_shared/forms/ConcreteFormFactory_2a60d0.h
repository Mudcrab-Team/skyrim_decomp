// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and published community declarations).
// TESImageSpace, ConcreteFormFactory, CreateImpl, GetFormName, GetFormType, _name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnregisterFormFactory and integral argument types: GUESS(low) STANDIN
// Code origin: original explicit instantiation of the form-factory destructor template.
#pragma once

#include "IFormFactory.h"

class TESImageSpace;

template<class T, unsigned char FormType>
class ConcreteFormFactory : public IFormFactory
{
public:
    ~ConcreteFormFactory() override { UnregisterFormFactory(FormType); }
    TESForm* CreateImpl() override;
    const char* GetFormName() const override;
    unsigned char GetFormType() const override;

protected:
    const char* _name;
};
