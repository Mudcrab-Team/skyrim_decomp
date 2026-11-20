// Source exposure: binary-analysis
// DeletingLeaf1172640, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1172640 {
public:
    virtual ~DeletingLeaf1172640() {}
};
static_assert(sizeof(DeletingLeaf1172640) == 8, "minimal virtual interface size");
