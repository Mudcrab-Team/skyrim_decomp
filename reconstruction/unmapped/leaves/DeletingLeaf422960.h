// Source exposure: binary-analysis
// DeletingLeaf422960, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf422960 {
public:
    virtual ~DeletingLeaf422960() {}
};
static_assert(sizeof(DeletingLeaf422960) == 8, "minimal virtual interface size");
