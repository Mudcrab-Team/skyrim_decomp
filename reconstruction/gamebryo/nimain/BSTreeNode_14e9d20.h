// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSLeafAnimNode, BSTreeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// TreeArrayAllocator, TreeArrayAllocator::Deallocate, TreeArrayAllocator::QData, TreeArrayAllocator::data, TreeArrayAllocator::capacity, TreeArraySize, TreeArraySize::size, TreeArraySize::unk04, TreeArray, BSLeafAnimNode::unk08, BSTreeNode::unk170, BSTreeNode::array1, BSTreeNode::array2: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class TreeArrayAllocator
{
public:
    ~TreeArrayAllocator();
    void Deallocate();
    void* QData() const { return data; }

    void* data;
    std::uint64_t capacity;
};

class TreeArraySize
{
public:
    ~TreeArraySize();

    std::uint32_t size;
    std::uint32_t unk04;
};

class TreeArray : public TreeArrayAllocator, public TreeArraySize
{
public:
    ~TreeArray()
    {
        if (QData()) {
            Deallocate();
            size = 0;
        }
    }
};
static_assert(offsetof(TreeArray, size) == 0x10, "size offset");
static_assert(sizeof(TreeArray) == 0x18, "TreeArray size");

class BSLeafAnimNode
{
public:
    virtual ~BSLeafAnimNode();

    std::uint8_t unk08[0x168];
};
static_assert(sizeof(BSLeafAnimNode) == 0x170, "BSLeafAnimNode size");

class BSTreeNode : public BSLeafAnimNode
{
public:
    BSTreeNode();
    ~BSTreeNode() override;

    std::uint8_t unk170[0x18];
    TreeArray array1;
    TreeArray array2;
};
static_assert(offsetof(BSTreeNode, array1) == 0x188, "array1 offset");
static_assert(offsetof(BSTreeNode, array2) == 0x1A0, "array2 offset");
static_assert(sizeof(BSTreeNode) == 0x1B8, "BSTreeNode size");
