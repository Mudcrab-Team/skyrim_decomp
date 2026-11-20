// Source exposure: binary-analysis
// Static1085d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1085d0;
extern void construct(Static1085d0*, const Descriptor*);
extern void destroy(Static1085d0*);
struct Static1085d0 {
    void* value;
    Static1085d0() { construct(this, &descriptor); }
    ~Static1085d0() { destroy(this); }
};
