// Source exposure: binary-analysis
// DeletingLeaf8e9890, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8e9890 {
public:
    virtual ~DeletingLeaf8e9890() {}
};
static_assert(sizeof(DeletingLeaf8e9890) == 8, "minimal virtual interface size");
