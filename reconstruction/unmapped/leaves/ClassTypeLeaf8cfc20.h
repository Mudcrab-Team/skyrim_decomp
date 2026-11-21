// Source exposure: binary-analysis (the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; drafted from the pinned image listing
// ClassTypeLeaf8cfc20, QClassType, StaticValue: GUESS(low) STANDIN
#pragma once

class ClassTypeLeaf8cfc20 {
public:
    struct StaticValue {
        StaticValue(const char* a_text);
        ~StaticValue();

        const char* data;
    };

    static StaticValue* QClassType();
};
