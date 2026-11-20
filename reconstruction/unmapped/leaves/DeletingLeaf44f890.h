// Source exposure: binary-analysis
// DeletingLeaf44f890, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf44f890 {
public:
    virtual ~DeletingLeaf44f890() {}
};
static_assert(sizeof(DeletingLeaf44f890) == 8, "minimal virtual interface size");
