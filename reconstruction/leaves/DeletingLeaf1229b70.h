// Source exposure: binary-analysis
// DeletingLeaf1229b70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1229b70 {
public:
    virtual ~DeletingLeaf1229b70() {}
};
static_assert(sizeof(DeletingLeaf1229b70) == 8, "minimal virtual interface size");
