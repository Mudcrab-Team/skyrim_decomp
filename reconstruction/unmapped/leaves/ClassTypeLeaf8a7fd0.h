// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8a7fd0 ClassTypeLeaf8a7fd0::QClassType
// ClassTypeLeaf8a7fd0::QClassType, Type, its constructor and destructor: GUESS(low) STANDIN
#pragma once

class ClassTypeLeaf8a7fd0
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
