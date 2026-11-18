// Source exposure: binary-analysis
// DeletingLeaf661ba0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf661ba0 {
public:
    virtual ~DeletingLeaf661ba0() {}
};
static_assert(sizeof(DeletingLeaf661ba0) == 8, "minimal virtual interface size");
