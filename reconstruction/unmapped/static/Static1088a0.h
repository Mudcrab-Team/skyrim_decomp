// Source exposure: binary-analysis
// Static1088a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1088a0;
extern void construct(Static1088a0*, const Descriptor*);
extern void destroy(Static1088a0*);
struct Static1088a0 {
    void* value;
    Static1088a0() { construct(this, &descriptor); }
    ~Static1088a0() { destroy(this); }
};
