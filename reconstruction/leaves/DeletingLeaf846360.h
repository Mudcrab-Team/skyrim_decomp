// Source exposure: binary-analysis
// DeletingLeaf846360, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846360 {
public:
    virtual ~DeletingLeaf846360() {}
};
static_assert(sizeof(DeletingLeaf846360) == 8, "minimal virtual interface size");
