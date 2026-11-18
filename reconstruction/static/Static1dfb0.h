// Source exposure: binary-analysis
// Static1dfb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dfb0;
extern void construct(Static1dfb0*, const Descriptor*);
extern void destroy(Static1dfb0*);
struct Static1dfb0 {
    void* value;
    Static1dfb0() { construct(this, &descriptor); }
    ~Static1dfb0() { destroy(this); }
};
