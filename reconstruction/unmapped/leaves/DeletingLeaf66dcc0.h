// Source exposure: binary-analysis
// DeletingLeaf66dcc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66dcc0 {
public:
    virtual ~DeletingLeaf66dcc0() {}
};
static_assert(sizeof(DeletingLeaf66dcc0) == 8, "minimal virtual interface size");
