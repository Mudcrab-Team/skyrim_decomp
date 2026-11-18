// Source exposure: binary-analysis
// DeletingLeaf809980, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809980 {
public:
    virtual ~DeletingLeaf809980() {}
};
static_assert(sizeof(DeletingLeaf809980) == 8, "minimal virtual interface size");
