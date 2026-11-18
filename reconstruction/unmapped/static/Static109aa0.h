// Source exposure: binary-analysis
// Static109aa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109aa0;
extern void construct(Static109aa0*, const Descriptor*);
extern void destroy(Static109aa0*);
struct Static109aa0 {
    void* value;
    Static109aa0() { construct(this, &descriptor); }
    ~Static109aa0() { destroy(this); }
};
