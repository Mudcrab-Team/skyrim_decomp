// Source exposure: binary-analysis
// DeletingLeaf830aa0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830aa0 {
public:
    virtual ~DeletingLeaf830aa0() {}
};
static_assert(sizeof(DeletingLeaf830aa0) == 8, "minimal virtual interface size");
