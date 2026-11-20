// Source exposure: binary-analysis
// Static1080f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1080f0;
extern void construct(Static1080f0*, const Descriptor*);
extern void destroy(Static1080f0*);
struct Static1080f0 {
    void* value;
    Static1080f0() { construct(this, &descriptor); }
    ~Static1080f0() { destroy(this); }
};
