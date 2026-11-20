// Source exposure: binary-analysis
// Static1d3b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d3b0;
extern void construct(Static1d3b0*, const Descriptor*);
extern void destroy(Static1d3b0*);
struct Static1d3b0 {
    void* value;
    Static1d3b0() { construct(this, &descriptor); }
    ~Static1d3b0() { destroy(this); }
};
