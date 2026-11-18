// Source exposure: binary-analysis
// Static1d3e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d3e0;
extern void construct(Static1d3e0*, const Descriptor*);
extern void destroy(Static1d3e0*);
struct Static1d3e0 {
    void* value;
    Static1d3e0() { construct(this, &descriptor); }
    ~Static1d3e0() { destroy(this); }
};
