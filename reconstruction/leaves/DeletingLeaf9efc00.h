// Source exposure: binary-analysis
// DeletingLeaf9efc00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efc00 {
public:
    virtual ~DeletingLeaf9efc00() {}
};
static_assert(sizeof(DeletingLeaf9efc00) == 8, "minimal virtual interface size");
