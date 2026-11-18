// Source exposure: binary-analysis
// Static1dce0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dce0;
extern void construct(Static1dce0*, const Descriptor*);
extern void destroy(Static1dce0*);
struct Static1dce0 {
    void* value;
    Static1dce0() { construct(this, &descriptor); }
    ~Static1dce0() { destroy(this); }
};
