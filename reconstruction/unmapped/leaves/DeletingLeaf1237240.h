// Source exposure: binary-analysis
// DeletingLeaf1237240, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1237240 {
public:
    virtual ~DeletingLeaf1237240() {}
};
static_assert(sizeof(DeletingLeaf1237240) == 8, "minimal virtual interface size");
