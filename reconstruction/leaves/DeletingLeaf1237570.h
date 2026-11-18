// Source exposure: binary-analysis
// DeletingLeaf1237570, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1237570 {
public:
    virtual ~DeletingLeaf1237570() {}
};
static_assert(sizeof(DeletingLeaf1237570) == 8, "minimal virtual interface size");
