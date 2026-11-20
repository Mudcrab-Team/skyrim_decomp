// Source exposure: binary-analysis
// Static1014d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1014d0;
extern void construct(Static1014d0*, const Descriptor*);
extern void destroy(Static1014d0*);
struct Static1014d0 {
    void* value;
    Static1014d0() { construct(this, &descriptor); }
    ~Static1014d0() { destroy(this); }
};
