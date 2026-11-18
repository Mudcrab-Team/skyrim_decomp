// Source exposure: binary-analysis
// DeletingLeaf66e300, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66e300 {
public:
    virtual ~DeletingLeaf66e300() {}
};
static_assert(sizeof(DeletingLeaf66e300) == 8, "minimal virtual interface size");
