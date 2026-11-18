// Source exposure: binary-analysis
// DeletingLeaf8e6910, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8e6910 {
public:
    virtual ~DeletingLeaf8e6910() {}
};
static_assert(sizeof(DeletingLeaf8e6910) == 8, "minimal virtual interface size");
