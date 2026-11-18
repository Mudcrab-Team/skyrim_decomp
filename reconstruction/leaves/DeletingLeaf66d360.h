// Source exposure: binary-analysis
// DeletingLeaf66d360, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66d360 {
public:
    virtual ~DeletingLeaf66d360() {}
};
static_assert(sizeof(DeletingLeaf66d360) == 8, "minimal virtual interface size");
