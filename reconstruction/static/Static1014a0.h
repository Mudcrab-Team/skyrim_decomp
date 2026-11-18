// Source exposure: binary-analysis
// Static1014a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1014a0;
extern void construct(Static1014a0*, const Descriptor*);
extern void destroy(Static1014a0*);
struct Static1014a0 {
    void* value;
    Static1014a0() { construct(this, &descriptor); }
    ~Static1014a0() { destroy(this); }
};
