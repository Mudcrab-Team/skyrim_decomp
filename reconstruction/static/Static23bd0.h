// Source exposure: binary-analysis
// Static23bd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23bd0;
extern void construct(Static23bd0*, const Descriptor*);
extern void destroy(Static23bd0*);
struct Static23bd0 {
    void* value;
    Static23bd0() { construct(this, &descriptor); }
    ~Static23bd0() { destroy(this); }
};
