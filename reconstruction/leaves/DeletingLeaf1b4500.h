// Source exposure: binary-analysis
// DeletingLeaf1b4500, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1b4500 {
public:
    virtual ~DeletingLeaf1b4500() {}
};
static_assert(sizeof(DeletingLeaf1b4500) == 8, "minimal virtual interface size");
