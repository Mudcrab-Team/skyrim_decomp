// Source exposure: binary-analysis
// DeletingLeaf4dff40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4dff40 {
public:
    virtual ~DeletingLeaf4dff40() {}
};
static_assert(sizeof(DeletingLeaf4dff40) == 8, "minimal virtual interface size");
