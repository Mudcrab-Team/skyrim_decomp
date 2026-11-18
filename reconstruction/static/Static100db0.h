// Source exposure: binary-analysis
// Static100db0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100db0;
extern void construct(Static100db0*, const Descriptor*);
extern void destroy(Static100db0*);
struct Static100db0 {
    void* value;
    Static100db0() { construct(this, &descriptor); }
    ~Static100db0() { destroy(this); }
};
