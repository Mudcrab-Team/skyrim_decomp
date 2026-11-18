// Source exposure: binary-analysis
// DeletingLeaf482b20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf482b20 {
public:
    virtual ~DeletingLeaf482b20() {}
};
static_assert(sizeof(DeletingLeaf482b20) == 8, "minimal virtual interface size");
