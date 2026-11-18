// Source exposure: binary-analysis
// DeletingLeaf122bdf0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122bdf0 {
public:
    virtual ~DeletingLeaf122bdf0() {}
};
static_assert(sizeof(DeletingLeaf122bdf0) == 8, "minimal virtual interface size");
