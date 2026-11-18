// Source exposure: binary-analysis
// DeletingLeaf1216d20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1216d20 {
public:
    virtual ~DeletingLeaf1216d20() {}
};
static_assert(sizeof(DeletingLeaf1216d20) == 8, "minimal virtual interface size");
