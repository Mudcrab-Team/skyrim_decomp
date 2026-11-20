// Source exposure: binary-analysis
// Static1add0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1add0;
extern void construct(Static1add0*, const Descriptor*);
extern void destroy(Static1add0*);
struct Static1add0 {
    void* value;
    Static1add0() { construct(this, &descriptor); }
    ~Static1add0() { destroy(this); }
};
