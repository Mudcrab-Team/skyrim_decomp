// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and published community declarations).
// BGSLocation, GetObjectName, GetObjectType, GetObjectCategory: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ConcreteObjectFormFactory: EXE_RTTI
// UnregisterFormFactory and integral argument types: GUESS(low) STANDIN
// Code origin: original explicit instantiation of the form-factory destructor template.
#pragma once

#include "ConcreteFormFactory.h"

class BGSLocation;

template<class T, unsigned char FormType, unsigned int ObjectType, unsigned int Category>
class ConcreteObjectFormFactory : public ConcreteFormFactory<T, FormType>
{
public:
    ConcreteObjectFormFactory() {}
    const char* GetObjectName() const override;
    unsigned int GetObjectType() const override;
    unsigned int GetObjectCategory() const override;
};
