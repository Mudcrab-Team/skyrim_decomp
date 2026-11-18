// Source exposure: binary-analysis
// Static1dda0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dda0;
extern void construct(Static1dda0*, const Descriptor*);
extern void destroy(Static1dda0*);
struct Static1dda0 {
    void* value;
    Static1dda0() { construct(this, &descriptor); }
    ~Static1dda0() { destroy(this); }
};
