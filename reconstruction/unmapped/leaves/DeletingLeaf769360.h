// Source exposure: binary-analysis
// DeletingLeaf769360, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf769360 {
public:
    virtual ~DeletingLeaf769360() {}
};
static_assert(sizeof(DeletingLeaf769360) == 8, "minimal virtual interface size");
