// Source exposure: binary-analysis
// DeletingLeaf240680, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf240680 {
public:
    virtual ~DeletingLeaf240680() {}
};
static_assert(sizeof(DeletingLeaf240680) == 8, "minimal virtual interface size");
