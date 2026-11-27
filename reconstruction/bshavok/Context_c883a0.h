// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Context: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Context::Func00d2edd0: GUESS(low); placeholder name
#pragma once

extern float Data0104da48;
struct hkpSymmetricAgentFlipCollector
{
    virtual void dispose();
    virtual void collect(float value);
    virtual void process(void* value);
    float threshold;
    void* object;
};
struct Context
{
    void Func00d43880(void* first, void* second, void* third, hkpSymmetricAgentFlipCollector* collector);
    void Func00d2edd0(void* first, void* second, void* third, void* fourth);
};
