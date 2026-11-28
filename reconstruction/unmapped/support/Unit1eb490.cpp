// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1eb490 Unit1eb490::BuildObjectPath1eb490
// Adapted bodies: none
#include "Unit1eb490.h"

// Dynamically casts the object to PathOwner1eb490, copies its path, and replaces its extension.
void Unit1eb490::BuildObjectPath1eb490(char* a_buffer, BaseObject1eb490* a_object)
{
    if (!a_object) {
        return;
    }

    PathOwner1eb490* owner = dynamic_cast<PathOwner1eb490*>(a_object);
    if (owner) {
        strcpy_s(a_buffer, 260, owner->GetPath());
        char* dot = strrchr(a_buffer, '.');
        if (dot) {
            strcpy_s(dot, 260 - static_cast<std::size_t>(dot - a_buffer), g_extension1eb490);
        }
    }
}
