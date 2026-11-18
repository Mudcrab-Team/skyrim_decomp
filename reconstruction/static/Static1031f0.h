// Source exposure: binary-analysis
// Static1031f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1031f0;
extern void construct(Static1031f0*, const Descriptor*);
extern void destroy(Static1031f0*);
struct Static1031f0 {
    void* value;
    Static1031f0() { construct(this, &descriptor); }
    ~Static1031f0() { destroy(this); }
};
