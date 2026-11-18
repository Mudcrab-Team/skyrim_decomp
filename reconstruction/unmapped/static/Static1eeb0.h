// Source exposure: binary-analysis
// Static1eeb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1eeb0;
extern void construct(Static1eeb0*, const Descriptor*);
extern void destroy(Static1eeb0*);
struct Static1eeb0 {
    void* value;
    Static1eeb0() { construct(this, &descriptor); }
    ~Static1eeb0() { destroy(this); }
};
