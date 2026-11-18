// Source exposure: binary-analysis
// Static1b4c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b4c0;
extern void construct(Static1b4c0*, const Descriptor*);
extern void destroy(Static1b4c0*);
struct Static1b4c0 {
    void* value;
    Static1b4c0() { construct(this, &descriptor); }
    ~Static1b4c0() { destroy(this); }
};
