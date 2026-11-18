// Source exposure: binary-analysis
// DeletingLeaf848250, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf848250 {
public:
    virtual ~DeletingLeaf848250() {}
};
static_assert(sizeof(DeletingLeaf848250) == 8, "minimal virtual interface size");
