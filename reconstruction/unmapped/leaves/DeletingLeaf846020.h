// Source exposure: binary-analysis
// DeletingLeaf846020, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846020 {
public:
    virtual ~DeletingLeaf846020() {}
};
static_assert(sizeof(DeletingLeaf846020) == 8, "minimal virtual interface size");
