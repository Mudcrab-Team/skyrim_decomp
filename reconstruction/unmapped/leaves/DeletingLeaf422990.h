// Source exposure: binary-analysis
// DeletingLeaf422990, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf422990 {
public:
    virtual ~DeletingLeaf422990() {}
};
static_assert(sizeof(DeletingLeaf422990) == 8, "minimal virtual interface size");
