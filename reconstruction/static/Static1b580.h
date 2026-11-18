// Source exposure: binary-analysis
// Static1b580, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b580;
extern void construct(Static1b580*, const Descriptor*);
extern void destroy(Static1b580*);
struct Static1b580 {
    void* value;
    Static1b580() { construct(this, &descriptor); }
    ~Static1b580() { destroy(this); }
};
