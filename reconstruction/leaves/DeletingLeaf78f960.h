// Source exposure: binary-analysis
// DeletingLeaf78f960, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf78f960 {
public:
    virtual ~DeletingLeaf78f960() {}
};
static_assert(sizeof(DeletingLeaf78f960) == 8, "minimal virtual interface size");
