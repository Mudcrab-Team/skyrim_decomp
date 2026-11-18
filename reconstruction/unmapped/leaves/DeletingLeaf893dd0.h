// Source exposure: binary-analysis
// DeletingLeaf893dd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893dd0 {
public:
    virtual ~DeletingLeaf893dd0() {}
};
static_assert(sizeof(DeletingLeaf893dd0) == 8, "minimal virtual interface size");
