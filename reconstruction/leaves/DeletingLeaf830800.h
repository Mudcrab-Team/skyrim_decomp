// Source exposure: binary-analysis
// DeletingLeaf830800, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830800 {
public:
    virtual ~DeletingLeaf830800() {}
};
static_assert(sizeof(DeletingLeaf830800) == 8, "minimal virtual interface size");
