// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1163d0
// Adapted bodies: none.
// TreeNode1163d0, FreeNode1163d0: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <memory>
#include <string>

struct TreeNode1163d0 {
    TreeNode1163d0* left;
    TreeNode1163d0* parent;
    TreeNode1163d0* right;
    std::uint8_t color;
    std::uint8_t isNil;
    std::uint64_t key;
    std::string value;
};

static_assert(sizeof(TreeNode1163d0) == 0x48, "TreeNode1163d0 size");

void FreeNode1163d0(std::allocator<TreeNode1163d0>& a_alloc, TreeNode1163d0* a_node);
