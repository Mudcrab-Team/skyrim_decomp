// Source exposure: binary-analysis
// DeletingLeaf458900, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458900 {
public:
    virtual ~DeletingLeaf458900() {}
};
static_assert(sizeof(DeletingLeaf458900) == 8, "minimal virtual interface size");
