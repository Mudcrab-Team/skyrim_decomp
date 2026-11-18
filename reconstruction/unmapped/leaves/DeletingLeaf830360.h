// Source exposure: binary-analysis
// DeletingLeaf830360, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830360 {
public:
    virtual ~DeletingLeaf830360() {}
};
static_assert(sizeof(DeletingLeaf830360) == 8, "minimal virtual interface size");
