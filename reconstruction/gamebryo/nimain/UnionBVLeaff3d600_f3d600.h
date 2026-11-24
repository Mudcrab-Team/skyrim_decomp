// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiUnionBV: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once

void ReleaseUnionArray(void* memory);
class UnionBVBase
{
public:
    virtual ~UnionBVBase();
};
class UnionChildren
{
public:
    virtual ~UnionChildren();
    void* items;
};
class UnionBVLeaff3d600 : public UnionBVBase
{
public:
    ~UnionBVLeaff3d600() override;
    void RemoveChildren() noexcept;
    UnionChildren children;
};
