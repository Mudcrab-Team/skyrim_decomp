// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00d481d0: GUESS(low); placeholder name
// Func00d481d0::Func00d481d0: GUESS(low); placeholder name
#pragma once

struct D481D0Class;
struct D481D0ReferencedObject;


struct D481D0StringPtr
{
    const char* m_pcText;

    D481D0StringPtr();
    void operator=(const char* s);
};

struct D481D0Class
{
    const char* getName() const;
};

struct D481D0ReferencedObject;

struct D481D0RefVariant
{
    D481D0ReferencedObject* m_ptr;

    D481D0RefVariant() : m_ptr(0)
    {}
    void set(D481D0ReferencedObject* obj, const D481D0Class* pClassInfo);
    const D481D0Class* GetVariantValue() const;
};

struct Func00d481d0
{
    D481D0StringPtr m_name;
    D481D0StringPtr m_pClassName;
    D481D0RefVariant m_pReferencedResource;

    Func00d481d0(const char* name, D481D0ReferencedObject* object, const D481D0Class* pClassInfo);
};
