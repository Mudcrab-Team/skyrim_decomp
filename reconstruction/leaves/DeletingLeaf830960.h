// Source exposure: binary-analysis
// DeletingLeaf830960, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830960 {
public:
    virtual ~DeletingLeaf830960() {}
};
static_assert(sizeof(DeletingLeaf830960) == 8, "minimal virtual interface size");
