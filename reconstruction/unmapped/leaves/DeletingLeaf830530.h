// Source exposure: binary-analysis
// DeletingLeaf830530, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830530 {
public:
    virtual ~DeletingLeaf830530() {}
};
static_assert(sizeof(DeletingLeaf830530) == 8, "minimal virtual interface size");
