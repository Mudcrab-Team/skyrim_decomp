// Source exposure: binary-analysis
// Static1034f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1034f0;
extern void construct(Static1034f0*, const Descriptor*);
extern void destroy(Static1034f0*);
struct Static1034f0 {
    void* value;
    Static1034f0() { construct(this, &descriptor); }
    ~Static1034f0() { destroy(this); }
};
