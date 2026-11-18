// Source exposure: binary-analysis
// DeletingLeaf80fd90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80fd90 {
public:
    virtual ~DeletingLeaf80fd90() {}
};
static_assert(sizeof(DeletingLeaf80fd90) == 8, "minimal virtual interface size");
