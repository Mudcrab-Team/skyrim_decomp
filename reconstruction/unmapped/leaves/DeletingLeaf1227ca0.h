// Source exposure: binary-analysis
// DeletingLeaf1227ca0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1227ca0 {
public:
    virtual ~DeletingLeaf1227ca0() {}
};
static_assert(sizeof(DeletingLeaf1227ca0) == 8, "minimal virtual interface size");
