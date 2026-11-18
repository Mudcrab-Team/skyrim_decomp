// Source exposure: binary-analysis
// Static1dec0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dec0;
extern void construct(Static1dec0*, const Descriptor*);
extern void destroy(Static1dec0*);
struct Static1dec0 {
    void* value;
    Static1dec0() { construct(this, &descriptor); }
    ~Static1dec0() { destroy(this); }
};
