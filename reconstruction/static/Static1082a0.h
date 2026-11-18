// Source exposure: binary-analysis
// Static1082a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1082a0;
extern void construct(Static1082a0*, const Descriptor*);
extern void destroy(Static1082a0*);
struct Static1082a0 {
    void* value;
    Static1082a0() { construct(this, &descriptor); }
    ~Static1082a0() { destroy(this); }
};
