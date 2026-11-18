// Source exposure: binary-analysis
// DeletingLeaf66d750, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66d750 {
public:
    virtual ~DeletingLeaf66d750() {}
};
static_assert(sizeof(DeletingLeaf66d750) == 8, "minimal virtual interface size");
