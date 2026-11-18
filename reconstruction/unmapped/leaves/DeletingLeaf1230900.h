// Source exposure: binary-analysis
// DeletingLeaf1230900, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1230900 {
public:
    virtual ~DeletingLeaf1230900() {}
};
static_assert(sizeof(DeletingLeaf1230900) == 8, "minimal virtual interface size");
