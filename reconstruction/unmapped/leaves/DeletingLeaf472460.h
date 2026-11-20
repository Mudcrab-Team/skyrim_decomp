// Source exposure: binary-analysis
// DeletingLeaf472460, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf472460 {
public:
    virtual ~DeletingLeaf472460() {}
};
static_assert(sizeof(DeletingLeaf472460) == 8, "minimal virtual interface size");
