// Source exposure: binary-analysis
// DeletingLeaf54ceb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf54ceb0 {
public:
    virtual ~DeletingLeaf54ceb0() {}
};
static_assert(sizeof(DeletingLeaf54ceb0) == 8, "minimal virtual interface size");
