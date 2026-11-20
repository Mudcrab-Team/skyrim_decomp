// Source exposure: binary-analysis
// DeletingLeaf830fd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830fd0 {
public:
    virtual ~DeletingLeaf830fd0() {}
};
static_assert(sizeof(DeletingLeaf830fd0) == 8, "minimal virtual interface size");
