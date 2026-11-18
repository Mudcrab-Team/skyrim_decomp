// Source exposure: binary-analysis
// DeletingLeaf66f970, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66f970 {
public:
    virtual ~DeletingLeaf66f970() {}
};
static_assert(sizeof(DeletingLeaf66f970) == 8, "minimal virtual interface size");
