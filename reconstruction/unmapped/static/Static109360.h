// Source exposure: binary-analysis
// Static109360, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109360;
extern void construct(Static109360*, const Descriptor*);
extern void destroy(Static109360*);
struct Static109360 {
    void* value;
    Static109360() { construct(this, &descriptor); }
    ~Static109360() { destroy(this); }
};
