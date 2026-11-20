// Source exposure: binary-analysis
// Static1016b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1016b0;
extern void construct(Static1016b0*, const Descriptor*);
extern void destroy(Static1016b0*);
struct Static1016b0 {
    void* value;
    Static1016b0() { construct(this, &descriptor); }
    ~Static1016b0() { destroy(this); }
};
