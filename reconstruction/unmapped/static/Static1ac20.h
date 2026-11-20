// Source exposure: binary-analysis
// Static1ac20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ac20;
extern void construct(Static1ac20*, const Descriptor*);
extern void destroy(Static1ac20*);
struct Static1ac20 {
    void* value;
    Static1ac20() { construct(this, &descriptor); }
    ~Static1ac20() { destroy(this); }
};
