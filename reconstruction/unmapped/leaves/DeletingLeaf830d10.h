// Source exposure: binary-analysis
// DeletingLeaf830d10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830d10 {
public:
    virtual ~DeletingLeaf830d10() {}
};
static_assert(sizeof(DeletingLeaf830d10) == 8, "minimal virtual interface size");
