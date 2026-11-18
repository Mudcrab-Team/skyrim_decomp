// Source exposure: binary-analysis
// DeletingLeaf1224080, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1224080 {
public:
    virtual ~DeletingLeaf1224080() {}
};
static_assert(sizeof(DeletingLeaf1224080) == 8, "minimal virtual interface size");
