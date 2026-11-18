// Source exposure: binary-analysis
// DeletingLeaf504200, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf504200 {
public:
    virtual ~DeletingLeaf504200() {}
};
static_assert(sizeof(DeletingLeaf504200) == 8, "minimal virtual interface size");
