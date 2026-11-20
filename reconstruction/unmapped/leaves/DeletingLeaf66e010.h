// Source exposure: binary-analysis
// DeletingLeaf66e010, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66e010 {
public:
    virtual ~DeletingLeaf66e010() {}
};
static_assert(sizeof(DeletingLeaf66e010) == 8, "minimal virtual interface size");
