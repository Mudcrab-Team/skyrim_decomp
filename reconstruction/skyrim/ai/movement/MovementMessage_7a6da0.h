// Source exposure: mixed (names from the community PDB table where labelled; sizes from the pinned image listing).
// Code origin: original; a class with a virtual destructor, sized from the target; the sibling decompilation only pointed at the shape.
// SPDX-License-Identifier: CC0-1.0
// MovementMessage, MovementMessage::~MovementMessage: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

class MovementMessage
{
  public:
    MovementMessage();
    virtual ~MovementMessage();
    char padding_[8];
};
