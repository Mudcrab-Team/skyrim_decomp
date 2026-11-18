// Source exposure: binary-analysis
// DeletingLeaf11f0240, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11f0240 {
public:
    virtual ~DeletingLeaf11f0240() {}
};
static_assert(sizeof(DeletingLeaf11f0240) == 8, "minimal virtual interface size");
