// Source exposure: binary-analysis
// DeletingLeaf83e640, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83e640 {
public:
    virtual ~DeletingLeaf83e640() {}
};
static_assert(sizeof(DeletingLeaf83e640) == 8, "minimal virtual interface size");
