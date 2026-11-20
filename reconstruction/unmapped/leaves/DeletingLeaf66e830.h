// Source exposure: binary-analysis
// DeletingLeaf66e830, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66e830 {
public:
    virtual ~DeletingLeaf66e830() {}
};
static_assert(sizeof(DeletingLeaf66e830) == 8, "minimal virtual interface size");
