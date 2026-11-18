// Source exposure: binary-analysis
// DeletingLeaf472350, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf472350 {
public:
    virtual ~DeletingLeaf472350() {}
};
static_assert(sizeof(DeletingLeaf472350) == 8, "minimal virtual interface size");
