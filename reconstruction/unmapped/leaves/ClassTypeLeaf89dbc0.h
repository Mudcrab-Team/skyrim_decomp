// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x89dbc0 ClassTypeLeaf89dbc0::QClassType
// ClassTypeLeaf89dbc0::QClassType, Type, its constructor and destructor: GUESS(low) STANDIN
#pragma once

class ClassTypeLeaf89dbc0
{
public:
    struct Type
    {
        Type(const char* a_name);
        ~Type();

        void* data;
    };

    static Type* QClassType();
};
