// Source exposure: binary-analysis
// DeletingLeaf461880, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf461880 {
public:
    virtual ~DeletingLeaf461880() {}
};
static_assert(sizeof(DeletingLeaf461880) == 8, "minimal virtual interface size");
