// Source exposure: binary-analysis
// DeletingLeaf1224700, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1224700 {
public:
    virtual ~DeletingLeaf1224700() {}
};
static_assert(sizeof(DeletingLeaf1224700) == 8, "minimal virtual interface size");
