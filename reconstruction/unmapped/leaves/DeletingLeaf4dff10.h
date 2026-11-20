// Source exposure: binary-analysis
// DeletingLeaf4dff10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4dff10 {
public:
    virtual ~DeletingLeaf4dff10() {}
};
static_assert(sizeof(DeletingLeaf4dff10) == 8, "minimal virtual interface size");
