// Source exposure: binary-analysis
// DeletingLeaf458600, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458600 {
public:
    virtual ~DeletingLeaf458600() {}
};
static_assert(sizeof(DeletingLeaf458600) == 8, "minimal virtual interface size");
