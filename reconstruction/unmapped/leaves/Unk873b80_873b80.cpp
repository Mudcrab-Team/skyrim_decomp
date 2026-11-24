// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x873b80 Indent
// Adapted bodies: Indent from the sibling source named in the header
#include "Unk873b80_873b80.h"

#include <cstring>

static char pstring[100];

char* Indent(unsigned int a_count)
{
    std::memset(pstring, ' ', a_count);
    pstring[a_count] = 0;
    return pstring;
}
