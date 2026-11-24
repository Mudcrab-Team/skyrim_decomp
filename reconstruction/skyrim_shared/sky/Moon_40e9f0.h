// Source exposure: mixed (names from the community PDB table where labelled; sizes from the pinned image listing).
// Code origin: original; a class with a virtual destructor, sized from the target; the sibling decompilation only pointed at the shape.
// SPDX-License-Identifier: CC0-1.0
// Moon, Moon::~Moon: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

class Moon
{
  public:
    Moon();
    virtual ~Moon();
    char padding_[208];
};
