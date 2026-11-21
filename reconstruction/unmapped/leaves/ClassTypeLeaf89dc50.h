// Source exposure: mixed (binary analysis and cited public declarations).
// Code origin: original; decoded from the pinned image listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x89dc50 ClassTypeLeaf89dc50::QClassType
// ClassTypeLeaf89dc50::QClassType, Type, its constructor and destructor: GUESS(low) STANDIN
#pragma once

class ClassTypeLeaf89dc50
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
