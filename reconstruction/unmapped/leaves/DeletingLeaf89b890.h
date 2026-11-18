// Source exposure: binary-analysis
// DeletingLeaf89b890, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf89b890 {
public:
    virtual ~DeletingLeaf89b890() {}
};
static_assert(sizeof(DeletingLeaf89b890) == 8, "minimal virtual interface size");
