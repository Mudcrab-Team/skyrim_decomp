// Source exposure: binary-analysis
// Static9f110, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f110;
extern void construct(Static9f110*, const Descriptor*);
extern void destroy(Static9f110*);
struct Static9f110 {
    void* value;
    Static9f110() { construct(this, &descriptor); }
    ~Static9f110() { destroy(this); }
};
