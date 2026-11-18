// Source exposure: binary-analysis
// DeletingLeaf98cd90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98cd90 {
public:
    virtual ~DeletingLeaf98cd90() {}
};
static_assert(sizeof(DeletingLeaf98cd90) == 8, "minimal virtual interface size");
