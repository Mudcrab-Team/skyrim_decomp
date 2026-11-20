// Source exposure: binary-analysis
// DeletingLeaf7a3b10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7a3b10 {
public:
    virtual ~DeletingLeaf7a3b10() {}
};
static_assert(sizeof(DeletingLeaf7a3b10) == 8, "minimal virtual interface size");
