// Source exposure: binary-analysis
// DeletingLeaf830400, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830400 {
public:
    virtual ~DeletingLeaf830400() {}
};
static_assert(sizeof(DeletingLeaf830400) == 8, "minimal virtual interface size");
