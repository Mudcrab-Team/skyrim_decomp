// Source exposure: binary-analysis
// DeletingLeaf1229bd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1229bd0 {
public:
    virtual ~DeletingLeaf1229bd0() {}
};
static_assert(sizeof(DeletingLeaf1229bd0) == 8, "minimal virtual interface size");
