// Source exposure: binary-analysis
// DeletingLeaf1216c10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1216c10 {
public:
    virtual ~DeletingLeaf1216c10() {}
};
static_assert(sizeof(DeletingLeaf1216c10) == 8, "minimal virtual interface size");
