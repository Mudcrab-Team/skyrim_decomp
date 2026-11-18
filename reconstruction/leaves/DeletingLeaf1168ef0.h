// Source exposure: binary-analysis
// DeletingLeaf1168ef0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1168ef0 {
public:
    virtual ~DeletingLeaf1168ef0() {}
};
static_assert(sizeof(DeletingLeaf1168ef0) == 8, "minimal virtual interface size");
