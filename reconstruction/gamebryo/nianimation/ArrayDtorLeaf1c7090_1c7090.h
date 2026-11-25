// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiTArray: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); used offset and object size observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
void ReleaseArrayMemory1c7090(void* memory);
class ArrayDtorBase1c7090
{
public:
    virtual ~ArrayDtorBase1c7090();
    void* data;
    std::uint64_t unknown10;
};
class ArrayDtorLeaf1c7090 : public ArrayDtorBase1c7090
{
public:
    ArrayDtorLeaf1c7090();
    ~ArrayDtorLeaf1c7090() override;
};
