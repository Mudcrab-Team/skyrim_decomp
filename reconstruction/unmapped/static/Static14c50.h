// Source exposure: binary-analysis
// Static14c50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14c50;
extern void construct(Static14c50*, const Descriptor*);
extern void destroy(Static14c50*);
struct Static14c50 {
    void* value;
    Static14c50() { construct(this, &descriptor); }
    ~Static14c50() { destroy(this); }
};
