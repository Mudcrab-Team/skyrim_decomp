// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSValueNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSValueNode::ParseIndexFromName: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfd35f0 BSValueNode::ParseIndexFromName
#include "BSValueNode_fd35f0.h"

#include <cstring>
#include <string>

// Parse a trailing numeric suffix from the node name into value.
bool BSValueNode::ParseIndexFromName()
{
    const char* str = name;
    const std::uint32_t len = static_cast<std::uint32_t>(std::strlen(str));
    std::uint32_t offset = 1;
    while (true) {
        bool valid = false;
        switch (str[len - offset]) {
        case '#':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '@':
            valid = true;
            break;
        default:
            break;
        }
        if (!valid || offset > len) {
            break;
        }
        ++offset;
    }

    str += len - offset + 1;
    const bool hasDigits = (*str != 0);
    value = std::atoi(str);
    return hasDigits;
}
