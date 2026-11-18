// Source exposure: binary-analysis
// DeletingLeaf893910, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893910 {
public:
    virtual ~DeletingLeaf893910() {}
};
static_assert(sizeof(DeletingLeaf893910) == 8, "minimal virtual interface size");
