// Source exposure: binary-analysis
// DeletingLeaf1f7c80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1f7c80 {
public:
    virtual ~DeletingLeaf1f7c80() {}
};
static_assert(sizeof(DeletingLeaf1f7c80) == 8, "minimal virtual interface size");
