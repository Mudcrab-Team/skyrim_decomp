// Source exposure: binary-analysis
// DeletingLeaf809d00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809d00 {
public:
    virtual ~DeletingLeaf809d00() {}
};
static_assert(sizeof(DeletingLeaf809d00) == 8, "minimal virtual interface size");
