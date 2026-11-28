// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xd0c840 Functiond0c840
// Adapted bodies: none
#include "FreeFunction_d0c840.h"

// Returns true if holder->child is non-null and its virtual type matches expectedType.
bool Functiond0c840(const Holderd0c840* holder, std::uint32_t expectedType)
{
    if (holder->child != nullptr && holder->child->GetType() == expectedType) {
        return true;
    }
    return false;
}
