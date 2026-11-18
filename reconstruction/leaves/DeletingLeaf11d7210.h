// Source exposure: binary-analysis
// DeletingLeaf11d7210, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11d7210 {
public:
    virtual ~DeletingLeaf11d7210() {}
};
static_assert(sizeof(DeletingLeaf11d7210) == 8, "minimal virtual interface size");
