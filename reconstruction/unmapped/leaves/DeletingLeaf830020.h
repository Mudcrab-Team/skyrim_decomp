// Source exposure: binary-analysis
// DeletingLeaf830020, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830020 {
public:
    virtual ~DeletingLeaf830020() {}
};
static_assert(sizeof(DeletingLeaf830020) == 8, "minimal virtual interface size");
