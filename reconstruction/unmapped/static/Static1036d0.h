// Source exposure: binary-analysis
// Static1036d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1036d0;
extern void construct(Static1036d0*, const Descriptor*);
extern void destroy(Static1036d0*);
struct Static1036d0 {
    void* value;
    Static1036d0() { construct(this, &descriptor); }
    ~Static1036d0() { destroy(this); }
};
