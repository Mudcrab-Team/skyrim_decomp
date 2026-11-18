// Source exposure: binary-analysis
// Static1085a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1085a0;
extern void construct(Static1085a0*, const Descriptor*);
extern void destroy(Static1085a0*);
struct Static1085a0 {
    void* value;
    Static1085a0() { construct(this, &descriptor); }
    ~Static1085a0() { destroy(this); }
};
