// Source exposure: binary-analysis
// DeletingLeaf66ec30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66ec30 {
public:
    virtual ~DeletingLeaf66ec30() {}
};
static_assert(sizeof(DeletingLeaf66ec30) == 8, "minimal virtual interface size");
