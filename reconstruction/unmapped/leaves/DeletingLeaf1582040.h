// Source exposure: binary-analysis
// DeletingLeaf1582040, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1582040 {
public:
    virtual ~DeletingLeaf1582040() {}
};
static_assert(sizeof(DeletingLeaf1582040) == 8, "minimal virtual interface size");
