// Source exposure: binary-analysis
// DeletingLeaf11f7920, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11f7920 {
public:
    virtual ~DeletingLeaf11f7920() {}
};
static_assert(sizeof(DeletingLeaf11f7920) == 8, "minimal virtual interface size");
