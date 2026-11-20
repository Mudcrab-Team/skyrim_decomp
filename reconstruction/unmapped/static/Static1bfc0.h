// Source exposure: binary-analysis
// Static1bfc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1bfc0;
extern void construct(Static1bfc0*, const Descriptor*);
extern void destroy(Static1bfc0*);
struct Static1bfc0 {
    void* value;
    Static1bfc0() { construct(this, &descriptor); }
    ~Static1bfc0() { destroy(this); }
};
