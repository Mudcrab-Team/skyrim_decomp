// Source exposure: binary-analysis
// DeletingLeaf830690, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830690 {
public:
    virtual ~DeletingLeaf830690() {}
};
static_assert(sizeof(DeletingLeaf830690) == 8, "minimal virtual interface size");
