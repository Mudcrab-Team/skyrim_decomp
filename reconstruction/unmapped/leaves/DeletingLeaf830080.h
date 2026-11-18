// Source exposure: binary-analysis
// DeletingLeaf830080, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830080 {
public:
    virtual ~DeletingLeaf830080() {}
};
static_assert(sizeof(DeletingLeaf830080) == 8, "minimal virtual interface size");
