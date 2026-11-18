// Source exposure: binary-analysis
// DeletingLeaf1c7130, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1c7130 {
public:
    virtual ~DeletingLeaf1c7130() {}
};
static_assert(sizeof(DeletingLeaf1c7130) == 8, "minimal virtual interface size");
