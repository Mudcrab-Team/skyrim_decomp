// Source exposure: binary-analysis
// DeletingLeaf816940, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf816940 {
public:
    virtual ~DeletingLeaf816940() {}
};
static_assert(sizeof(DeletingLeaf816940) == 8, "minimal virtual interface size");
