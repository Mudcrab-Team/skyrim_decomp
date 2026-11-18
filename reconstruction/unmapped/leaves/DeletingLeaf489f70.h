// Source exposure: binary-analysis
// DeletingLeaf489f70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf489f70 {
public:
    virtual ~DeletingLeaf489f70() {}
};
static_assert(sizeof(DeletingLeaf489f70) == 8, "minimal virtual interface size");
