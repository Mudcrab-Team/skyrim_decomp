// Source exposure: binary-analysis
// DeletingLeaf8cbbc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cbbc0 {
public:
    virtual ~DeletingLeaf8cbbc0() {}
};
static_assert(sizeof(DeletingLeaf8cbbc0) == 8, "minimal virtual interface size");
