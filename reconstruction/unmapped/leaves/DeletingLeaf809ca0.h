// Source exposure: binary-analysis
// DeletingLeaf809ca0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809ca0 {
public:
    virtual ~DeletingLeaf809ca0() {}
};
static_assert(sizeof(DeletingLeaf809ca0) == 8, "minimal virtual interface size");
