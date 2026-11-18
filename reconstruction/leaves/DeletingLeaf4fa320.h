// Source exposure: binary-analysis
// DeletingLeaf4fa320, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4fa320 {
public:
    virtual ~DeletingLeaf4fa320() {}
};
static_assert(sizeof(DeletingLeaf4fa320) == 8, "minimal virtual interface size");
