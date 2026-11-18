// Source exposure: binary-analysis
// DeletingLeaf66cf40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66cf40 {
public:
    virtual ~DeletingLeaf66cf40() {}
};
static_assert(sizeof(DeletingLeaf66cf40) == 8, "minimal virtual interface size");
