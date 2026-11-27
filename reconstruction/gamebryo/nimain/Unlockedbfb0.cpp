// Source exposure: mixed
// Code origin: Component transfer adapted from the cited Fallout 3 sibling.
// names: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); component transfer body adapted
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nipoint3.cpp:7
// Unlockedbfb0: GUESS(low) STANDIN; original owner is unknown
// Functionedbfb0: GUESS(low); provisional entry name
// 0xedbfb0 Unlockedbfb0::Functionedbfb0
#include "Unlockedbfb0.h"

void Unlockedbfb0::Functionedbfb0(Contextedbfb0* context)
{
    context->stream->Read(&x);
    context->stream->Read(&y);
    context->stream->Read(&z);
}
