// Source exposure: binary-analysis
// Static156d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static156d0;
extern void construct(Static156d0*, const Descriptor*);
extern void destroy(Static156d0*);
struct Static156d0 {
    void* value;
    Static156d0() { construct(this, &descriptor); }
    ~Static156d0() { destroy(this); }
};
