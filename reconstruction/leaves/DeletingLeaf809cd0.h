// Source exposure: binary-analysis
// DeletingLeaf809cd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809cd0 {
public:
    virtual ~DeletingLeaf809cd0() {}
};
static_assert(sizeof(DeletingLeaf809cd0) == 8, "minimal virtual interface size");
