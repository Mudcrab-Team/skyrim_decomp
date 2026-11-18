// Source exposure: binary-analysis
// DeletingLeaf9eff30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9eff30 {
public:
    virtual ~DeletingLeaf9eff30() {}
};
static_assert(sizeof(DeletingLeaf9eff30) == 8, "minimal virtual interface size");
