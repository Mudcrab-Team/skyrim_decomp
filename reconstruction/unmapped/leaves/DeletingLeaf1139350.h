// Source exposure: binary-analysis
// DeletingLeaf1139350, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1139350 {
public:
    virtual ~DeletingLeaf1139350() {}
};
static_assert(sizeof(DeletingLeaf1139350) == 8, "minimal virtual interface size");
