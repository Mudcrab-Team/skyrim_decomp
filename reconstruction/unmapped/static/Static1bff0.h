// Source exposure: binary-analysis
// Static1bff0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1bff0;
extern void construct(Static1bff0*, const Descriptor*);
extern void destroy(Static1bff0*);
struct Static1bff0 {
    void* value;
    Static1bff0() { construct(this, &descriptor); }
    ~Static1bff0() { destroy(this); }
};
