// Source exposure: binary-analysis
// DeletingLeaf82fa10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf82fa10 {
public:
    virtual ~DeletingLeaf82fa10() {}
};
static_assert(sizeof(DeletingLeaf82fa10) == 8, "minimal virtual interface size");
