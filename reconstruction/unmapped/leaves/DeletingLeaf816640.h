// Source exposure: binary-analysis
// DeletingLeaf816640, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf816640 {
public:
    virtual ~DeletingLeaf816640() {}
};
static_assert(sizeof(DeletingLeaf816640) == 8, "minimal virtual interface size");
