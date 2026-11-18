// Source exposure: binary-analysis
// DeletingLeaf14c8890, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf14c8890 {
public:
    virtual ~DeletingLeaf14c8890() {}
};
static_assert(sizeof(DeletingLeaf14c8890) == 8, "minimal virtual interface size");
