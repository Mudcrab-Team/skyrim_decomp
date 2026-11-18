// Source exposure: binary-analysis
// Static1012c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1012c0;
extern void construct(Static1012c0*, const Descriptor*);
extern void destroy(Static1012c0*);
struct Static1012c0 {
    void* value;
    Static1012c0() { construct(this, &descriptor); }
    ~Static1012c0() { destroy(this); }
};
