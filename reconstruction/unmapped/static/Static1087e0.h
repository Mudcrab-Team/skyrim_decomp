// Source exposure: binary-analysis
// Static1087e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1087e0;
extern void construct(Static1087e0*, const Descriptor*);
extern void destroy(Static1087e0*);
struct Static1087e0 {
    void* value;
    Static1087e0() { construct(this, &descriptor); }
    ~Static1087e0() { destroy(this); }
};
