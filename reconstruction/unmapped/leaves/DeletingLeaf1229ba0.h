// Source exposure: binary-analysis
// DeletingLeaf1229ba0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1229ba0 {
public:
    virtual ~DeletingLeaf1229ba0() {}
};
static_assert(sizeof(DeletingLeaf1229ba0) == 8, "minimal virtual interface size");
