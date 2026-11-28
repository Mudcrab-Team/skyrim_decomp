// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x1273e0 ItemList1273e0::~ItemList1273e0
// Adapted bodies: none
#include "ItemList1273e0.h"

// Deletes every owned item in the vector and destroys the vector storage.
ItemList1273e0::~ItemList1273e0()
{
    for (int i = 0; static_cast<std::size_t>(i) < items.size(); ++i)
    {
        delete items[i];
    }
}
