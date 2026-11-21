// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; the pinned image listing and the matched static-accessor shape only
// ClassTypeLeaf462720, ClassTypeLeaf462720::QClassType: GUESS(low)
// BSFixedString: STANDIN GUESS(low)
#pragma once

struct BSFixedString
{
    const char* data;
    BSFixedString(const char*);
    ~BSFixedString();
};

class ClassTypeLeaf462720
{
public:
    static const BSFixedString& QClassType();
};
