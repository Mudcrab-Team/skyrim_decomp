// Source exposure: binary-analysis
// Static109e60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109e60;
extern void construct(Static109e60*, const Descriptor*);
extern void destroy(Static109e60*);
struct Static109e60 {
    void* value;
    Static109e60() { construct(this, &descriptor); }
    ~Static109e60() { destroy(this); }
};
