// Source exposure: binary-analysis
// DeletingLeaf98cc60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98cc60 {
public:
    virtual ~DeletingLeaf98cc60() {}
};
static_assert(sizeof(DeletingLeaf98cc60) == 8, "minimal virtual interface size");
