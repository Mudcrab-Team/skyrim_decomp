// Source exposure: binary-analysis
// DeletingLeaf527d70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf527d70 {
public:
    virtual ~DeletingLeaf527d70() {}
};
static_assert(sizeof(DeletingLeaf527d70) == 8, "minimal virtual interface size");
