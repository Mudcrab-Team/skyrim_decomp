// Source exposure: mixed (pinned image and public declarations).
// Code origin: original virtual slot declarations for cell-grid detachment.
// GridArray, DetachAll, KillAll, SetCenter, Shift, Detach, ClearItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

#include "GridArrayLayout.h"

class GridArray : public ResearchLayouts::GridArrayLayout
{
public:
    virtual void DetachAll();
    virtual void KillAll();
    virtual bool SetCenter(std::int32_t x, std::int32_t y);
    virtual void Shift(std::int32_t x, std::int32_t y);
    virtual void Detach(std::uint32_t x, std::uint32_t y);
    virtual void ClearItem(std::uint32_t x, std::uint32_t y);
};
