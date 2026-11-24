// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiTArray: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); used offset and object size observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
void ReleaseArrayMemory221420(void* memory);
class ArrayDtorBase221420
{
public:
    virtual ~ArrayDtorBase221420();
    void* data;
    std::uint64_t unknown10;
};
class ArrayDtorLeaf221420 : public ArrayDtorBase221420
{
public:
    ArrayDtorLeaf221420();
    ~ArrayDtorLeaf221420() override;
};
