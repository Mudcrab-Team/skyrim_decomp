// Source exposure: binary-analysis
// DeletingLeaf830b30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830b30 {
public:
    virtual ~DeletingLeaf830b30() {}
};
static_assert(sizeof(DeletingLeaf830b30) == 8, "minimal virtual interface size");
