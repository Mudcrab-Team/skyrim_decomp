// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSImagespaceShader, BSShader, ImageSpaceEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the base order and sizes this function reads
// BSTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the destructor touches
// BSTArrayAllocator, BSTArraySize, BSTArray::QData, NiObject, NiBoneMatrixSetter, NiShaderSetter, BSReloadInterface, BSTArrayAllocator::Deallocate, BSImagespaceShader::array0, BSImagespaceShader::array1, BSImagespaceShader::array2, BSImagespaceShader::array3: GUESS(low); the array parts, the extra bases that hold the three vtable pointers, and names made up from the offsets
// BSImagespaceShader::unk120, BSImagespaceShader::unk198: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; regions the function does not access
#pragma once

#include <cstdint>
#include <cstddef>

class BSTArrayAllocator
{
public:
    ~BSTArrayAllocator();  // callee at 0xce0f30, not compared here
    void Deallocate();     // callee at 0xce0ed0, not compared here
    void* QData() const { return data; }

    void* data;
    std::uint64_t capacity;
};

class BSTArraySize
{
public:
    ~BSTArraySize();  // callee at 0xce0ca0, not compared here

    std::uint32_t size;
    std::uint32_t unk04;
};

class BSTArray : public BSTArrayAllocator, public BSTArraySize
{
public:
    ~BSTArray()
    {
        if (QData()) {
            Deallocate();
            size = 0;
        }
    }
};
static_assert(sizeof(BSTArray) == 0x18, "array size");

class NiObject
{
public:
    virtual ~NiObject() {}

    std::uint8_t unk08[8];
};

class NiBoneMatrixSetter
{
public:
    virtual void SetBoneMatrix();
};

class BSReloadInterface
{
public:
    virtual void Reload();

    std::uint8_t unk08[0x70];
};

class BSShader : public NiObject, public NiBoneMatrixSetter, public BSReloadInterface
{
public:
    ~BSShader() override;  // callee at 0x1578a30, not compared here
};
static_assert(sizeof(BSShader) == 0x90, "shader size");

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();  // callee at 0x1553a30, not compared here

    std::uint8_t unk08[0x88];
};

class BSImagespaceShader : public BSShader, public ImageSpaceEffect
{
public:
    BSImagespaceShader();  // the constructor makes the compiler emit the vftables and the deleting destructor at 0x1565310
    ~BSImagespaceShader() override;

    std::uint8_t unk120[0x18];  // 120
    BSTArray array0;            // 138
    BSTArray array1;            // 150
    BSTArray array2;            // 168
    BSTArray array3;            // 180
    std::uint8_t unk198[0x10];  // 198
};
static_assert(sizeof(BSImagespaceShader) == 0x1a8, "imagespace shader size");
