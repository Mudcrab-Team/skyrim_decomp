// Source exposure: binary-analysis
// DeletingLeaf832410, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832410 {
public:
    virtual ~DeletingLeaf832410() {}
};
static_assert(sizeof(DeletingLeaf832410) == 8, "minimal virtual interface size");
