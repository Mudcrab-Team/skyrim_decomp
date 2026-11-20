// Source exposure: binary-analysis
// Static109fb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109fb0;
extern void construct(Static109fb0*, const Descriptor*);
extern void destroy(Static109fb0*);
struct Static109fb0 {
    void* value;
    Static109fb0() { construct(this, &descriptor); }
    ~Static109fb0() { destroy(this); }
};
