// Source exposure: binary-analysis
// DeletingLeaf1497030, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1497030 {
public:
    virtual ~DeletingLeaf1497030() {}
};
static_assert(sizeof(DeletingLeaf1497030) == 8, "minimal virtual interface size");
