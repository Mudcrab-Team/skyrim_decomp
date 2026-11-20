// Source exposure: binary-analysis
// DeletingLeaf458570, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458570 {
public:
    virtual ~DeletingLeaf458570() {}
};
static_assert(sizeof(DeletingLeaf458570) == 8, "minimal virtual interface size");
