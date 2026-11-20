// Source exposure: binary-analysis
// DeletingLeaf458170, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458170 {
public:
    virtual ~DeletingLeaf458170() {}
};
static_assert(sizeof(DeletingLeaf458170) == 8, "minimal virtual interface size");
