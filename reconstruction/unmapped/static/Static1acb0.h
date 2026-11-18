// Source exposure: binary-analysis
// Static1acb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1acb0;
extern void construct(Static1acb0*, const Descriptor*);
extern void destroy(Static1acb0*);
struct Static1acb0 {
    void* value;
    Static1acb0() { construct(this, &descriptor); }
    ~Static1acb0() { destroy(this); }
};
