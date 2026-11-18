// Source exposure: binary-analysis
// Static1035b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1035b0;
extern void construct(Static1035b0*, const Descriptor*);
extern void destroy(Static1035b0*);
struct Static1035b0 {
    void* value;
    Static1035b0() { construct(this, &descriptor); }
    ~Static1035b0() { destroy(this); }
};
