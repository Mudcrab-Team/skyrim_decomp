// Source exposure: binary-analysis
// DeletingLeaf7e1080, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7e1080 {
public:
    virtual ~DeletingLeaf7e1080() {}
};
static_assert(sizeof(DeletingLeaf7e1080) == 8, "minimal virtual interface size");
