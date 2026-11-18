// Source exposure: binary-analysis
// DeletingLeaf490f10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf490f10 {
public:
    virtual ~DeletingLeaf490f10() {}
};
static_assert(sizeof(DeletingLeaf490f10) == 8, "minimal virtual interface size");
