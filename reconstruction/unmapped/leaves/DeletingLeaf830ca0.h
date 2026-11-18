// Source exposure: binary-analysis
// DeletingLeaf830ca0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830ca0 {
public:
    virtual ~DeletingLeaf830ca0() {}
};
static_assert(sizeof(DeletingLeaf830ca0) == 8, "minimal virtual interface size");
