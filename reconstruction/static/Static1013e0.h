// Source exposure: binary-analysis
// Static1013e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1013e0;
extern void construct(Static1013e0*, const Descriptor*);
extern void destroy(Static1013e0*);
struct Static1013e0 {
    void* value;
    Static1013e0() { construct(this, &descriptor); }
    ~Static1013e0() { destroy(this); }
};
