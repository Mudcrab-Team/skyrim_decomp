// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; the pinned image listing and the matched static-accessor shape only
// ClassTypeLeaf4653a0, ClassTypeLeaf4653a0::QClassType: GUESS(low)
// BSFixedString: STANDIN GUESS(low)
#pragma once

struct BSFixedString
{
    const char* data;
    BSFixedString(const char*);
    ~BSFixedString();
};

class ClassTypeLeaf4653a0
{
public:
    static const BSFixedString& QClassType();
};
