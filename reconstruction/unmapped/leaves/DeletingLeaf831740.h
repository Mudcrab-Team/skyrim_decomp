// Source exposure: binary-analysis
// DeletingLeaf831740, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831740 {
public:
    virtual ~DeletingLeaf831740() {}
};
static_assert(sizeof(DeletingLeaf831740) == 8, "minimal virtual interface size");
