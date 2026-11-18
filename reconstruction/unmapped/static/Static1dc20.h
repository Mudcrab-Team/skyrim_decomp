// Source exposure: binary-analysis
// Static1dc20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dc20;
extern void construct(Static1dc20*, const Descriptor*);
extern void destroy(Static1dc20*);
struct Static1dc20 {
    void* value;
    Static1dc20() { construct(this, &descriptor); }
    ~Static1dc20() { destroy(this); }
};
