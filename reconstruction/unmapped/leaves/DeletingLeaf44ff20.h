// Source exposure: binary-analysis
// DeletingLeaf44ff20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf44ff20 {
public:
    virtual ~DeletingLeaf44ff20() {}
};
static_assert(sizeof(DeletingLeaf44ff20) == 8, "minimal virtual interface size");
