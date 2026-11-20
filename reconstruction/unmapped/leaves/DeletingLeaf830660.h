// Source exposure: binary-analysis
// DeletingLeaf830660, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830660 {
public:
    virtual ~DeletingLeaf830660() {}
};
static_assert(sizeof(DeletingLeaf830660) == 8, "minimal virtual interface size");
