// Source exposure: binary-analysis
// DeletingLeaf121d920, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121d920 {
public:
    virtual ~DeletingLeaf121d920() {}
};
static_assert(sizeof(DeletingLeaf121d920) == 8, "minimal virtual interface size");
