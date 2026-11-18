// Source exposure: binary-analysis
// DeletingLeaf98d2e0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98d2e0 {
public:
    virtual ~DeletingLeaf98d2e0() {}
};
static_assert(sizeof(DeletingLeaf98d2e0) == 8, "minimal virtual interface size");
