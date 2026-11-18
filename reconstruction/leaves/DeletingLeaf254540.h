// Source exposure: binary-analysis
// DeletingLeaf254540, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf254540 {
public:
    virtual ~DeletingLeaf254540() {}
};
static_assert(sizeof(DeletingLeaf254540) == 8, "minimal virtual interface size");
