// Source exposure: binary-analysis
// DeletingLeaf4e0d20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4e0d20 {
public:
    virtual ~DeletingLeaf4e0d20() {}
};
static_assert(sizeof(DeletingLeaf4e0d20) == 8, "minimal virtual interface size");
