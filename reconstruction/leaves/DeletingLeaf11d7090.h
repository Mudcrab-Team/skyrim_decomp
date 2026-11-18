// Source exposure: binary-analysis
// DeletingLeaf11d7090, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11d7090 {
public:
    virtual ~DeletingLeaf11d7090() {}
};
static_assert(sizeof(DeletingLeaf11d7090) == 8, "minimal virtual interface size");
