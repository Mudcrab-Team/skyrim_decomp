// Source exposure: binary-analysis
// Static1082d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1082d0;
extern void construct(Static1082d0*, const Descriptor*);
extern void destroy(Static1082d0*);
struct Static1082d0 {
    void* value;
    Static1082d0() { construct(this, &descriptor); }
    ~Static1082d0() { destroy(this); }
};
