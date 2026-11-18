// Source exposure: binary-analysis
// DeletingLeaf849b00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849b00 {
public:
    virtual ~DeletingLeaf849b00() {}
};
static_assert(sizeof(DeletingLeaf849b00) == 8, "minimal virtual interface size");
