// Source exposure: binary-analysis
// DeletingLeaf9efe10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efe10 {
public:
    virtual ~DeletingLeaf9efe10() {}
};
static_assert(sizeof(DeletingLeaf9efe10) == 8, "minimal virtual interface size");
