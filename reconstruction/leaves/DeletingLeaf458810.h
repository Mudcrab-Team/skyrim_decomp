// Source exposure: binary-analysis
// DeletingLeaf458810, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458810 {
public:
    virtual ~DeletingLeaf458810() {}
};
static_assert(sizeof(DeletingLeaf458810) == 8, "minimal virtual interface size");
