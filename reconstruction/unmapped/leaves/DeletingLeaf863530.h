// Source exposure: binary-analysis
// DeletingLeaf863530, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf863530 {
public:
    virtual ~DeletingLeaf863530() {}
};
static_assert(sizeof(DeletingLeaf863530) == 8, "minimal virtual interface size");
