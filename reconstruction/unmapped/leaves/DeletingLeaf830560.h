// Source exposure: binary-analysis
// DeletingLeaf830560, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830560 {
public:
    virtual ~DeletingLeaf830560() {}
};
static_assert(sizeof(DeletingLeaf830560) == 8, "minimal virtual interface size");
