// Source exposure: binary-analysis
// DeletingLeaf66dec0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66dec0 {
public:
    virtual ~DeletingLeaf66dec0() {}
};
static_assert(sizeof(DeletingLeaf66dec0) == 8, "minimal virtual interface size");
