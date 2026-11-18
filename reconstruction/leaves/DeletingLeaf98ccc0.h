// Source exposure: binary-analysis
// DeletingLeaf98ccc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98ccc0 {
public:
    virtual ~DeletingLeaf98ccc0() {}
};
static_assert(sizeof(DeletingLeaf98ccc0) == 8, "minimal virtual interface size");
