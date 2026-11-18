// Source exposure: binary-analysis
// DeletingLeaf78fba0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf78fba0 {
public:
    virtual ~DeletingLeaf78fba0() {}
};
static_assert(sizeof(DeletingLeaf78fba0) == 8, "minimal virtual interface size");
