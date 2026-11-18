// Source exposure: binary-analysis
// DeletingLeaf422870, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf422870 {
public:
    virtual ~DeletingLeaf422870() {}
};
static_assert(sizeof(DeletingLeaf422870) == 8, "minimal virtual interface size");
