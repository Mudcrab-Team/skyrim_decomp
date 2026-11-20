// Source exposure: binary-analysis
// DeletingLeaf1227c10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1227c10 {
public:
    virtual ~DeletingLeaf1227c10() {}
};
static_assert(sizeof(DeletingLeaf1227c10) == 8, "minimal virtual interface size");
