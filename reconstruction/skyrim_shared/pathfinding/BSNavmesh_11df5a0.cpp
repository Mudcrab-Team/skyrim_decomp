// Source exposure: mixed
// Code origin: original reconstruction from the assigned local target; community declarations as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x11df5a0 BSNavmesh::ReadEdgeCover
#include "BSNavmesh_11df5a0.h"

// ReadEdgeCover: GUESS(low); original body from the assigned local target.
std::uint16_t BSNavmesh::ReadEdgeCover(std::uint16_t triangle, std::uint16_t edge, bool& left, bool& right) const
{
    std::uint32_t flags = triangles[triangle].triangleFlags;
    if ((flags & 0x0FBE0000) > 0) {
        flags >>= 16 + 6 * edge;
        left = (flags & 0x10) > 0;
        right = (flags & 0x20) > 0;
        std::uint8_t cover = static_cast<std::uint8_t>(flags);
        cover &= 0xF;
        return cover;
    }
    left = false;
    right = false;
    return 0;
}
