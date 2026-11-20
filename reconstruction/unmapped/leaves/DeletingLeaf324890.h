// Source exposure: binary-analysis
// DeletingLeaf324890, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf324890 {
public:
    virtual ~DeletingLeaf324890() {}
};
static_assert(sizeof(DeletingLeaf324890) == 8, "minimal virtual interface size");
