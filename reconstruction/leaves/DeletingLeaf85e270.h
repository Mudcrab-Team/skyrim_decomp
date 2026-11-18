// Source exposure: binary-analysis
// DeletingLeaf85e270, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf85e270 {
public:
    virtual ~DeletingLeaf85e270() {}
};
static_assert(sizeof(DeletingLeaf85e270) == 8, "minimal virtual interface size");
