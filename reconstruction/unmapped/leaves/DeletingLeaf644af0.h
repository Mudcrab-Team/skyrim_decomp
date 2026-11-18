// Source exposure: binary-analysis
// DeletingLeaf644af0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf644af0 {
public:
    virtual ~DeletingLeaf644af0() {}
};
static_assert(sizeof(DeletingLeaf644af0) == 8, "minimal virtual interface size");
