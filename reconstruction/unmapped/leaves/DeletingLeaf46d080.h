// Source exposure: binary-analysis
// DeletingLeaf46d080, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf46d080 {
public:
    virtual ~DeletingLeaf46d080() {}
};
static_assert(sizeof(DeletingLeaf46d080) == 8, "minimal virtual interface size");
