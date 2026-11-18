// Source exposure: binary-analysis
// Static1ddd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ddd0;
extern void construct(Static1ddd0*, const Descriptor*);
extern void destroy(Static1ddd0*);
struct Static1ddd0 {
    void* value;
    Static1ddd0() { construct(this, &descriptor); }
    ~Static1ddd0() { destroy(this); }
};
