// Source exposure: binary-analysis
// DeletingLeaf4f4160, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4f4160 {
public:
    virtual ~DeletingLeaf4f4160() {}
};
static_assert(sizeof(DeletingLeaf4f4160) == 8, "minimal virtual interface size");
