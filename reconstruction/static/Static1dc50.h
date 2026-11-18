// Source exposure: binary-analysis
// Static1dc50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dc50;
extern void construct(Static1dc50*, const Descriptor*);
extern void destroy(Static1dc50*);
struct Static1dc50 {
    void* value;
    Static1dc50() { construct(this, &descriptor); }
    ~Static1dc50() { destroy(this); }
};
