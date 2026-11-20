// Source exposure: binary-analysis
// DeletingLeaf13471b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf13471b0 {
public:
    virtual ~DeletingLeaf13471b0() {}
};
static_assert(sizeof(DeletingLeaf13471b0) == 8, "minimal virtual interface size");
