// Source exposure: binary-analysis
// Static1088d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1088d0;
extern void construct(Static1088d0*, const Descriptor*);
extern void destroy(Static1088d0*);
struct Static1088d0 {
    void* value;
    Static1088d0() { construct(this, &descriptor); }
    ~Static1088d0() { destroy(this); }
};
