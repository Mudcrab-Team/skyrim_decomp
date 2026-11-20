// Source exposure: binary-analysis
// DeletingLeaf893940, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893940 {
public:
    virtual ~DeletingLeaf893940() {}
};
static_assert(sizeof(DeletingLeaf893940) == 8, "minimal virtual interface size");
