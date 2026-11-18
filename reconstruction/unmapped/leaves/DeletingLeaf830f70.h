// Source exposure: binary-analysis
// DeletingLeaf830f70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830f70 {
public:
    virtual ~DeletingLeaf830f70() {}
};
static_assert(sizeof(DeletingLeaf830f70) == 8, "minimal virtual interface size");
