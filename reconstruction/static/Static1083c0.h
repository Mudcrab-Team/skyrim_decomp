// Source exposure: binary-analysis
// Static1083c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1083c0;
extern void construct(Static1083c0*, const Descriptor*);
extern void destroy(Static1083c0*);
struct Static1083c0 {
    void* value;
    Static1083c0() { construct(this, &descriptor); }
    ~Static1083c0() { destroy(this); }
};
