// Source exposure: binary-analysis
// DeletingLeaf4579c0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4579c0 {
public:
    virtual ~DeletingLeaf4579c0() {}
};
static_assert(sizeof(DeletingLeaf4579c0) == 8, "minimal virtual interface size");
