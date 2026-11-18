// Source exposure: binary-analysis
// DeletingLeaf893b10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893b10 {
public:
    virtual ~DeletingLeaf893b10() {}
};
static_assert(sizeof(DeletingLeaf893b10) == 8, "minimal virtual interface size");
