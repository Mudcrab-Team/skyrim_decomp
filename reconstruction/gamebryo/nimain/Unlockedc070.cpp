// Source exposure: mixed
// Code origin: Component transfer adapted from the cited Fallout 3 sibling.
// names: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); component transfer body adapted
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nipoint3.cpp:13
// Unlockedc070: GUESS(low) STANDIN; original owner is unknown
// Functionedc070: GUESS(low); provisional entry name
// 0xedc070 Unlockedc070::Functionedc070
#include "Unlockedc070.h"

void Unlockedc070::Functionedc070(Contextedc070* context)
{
    context->stream->Write(&x);
    context->stream->Write(&y);
    context->stream->Write(&z);
}
