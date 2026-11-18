// Source exposure: binary-analysis
// Static109f20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109f20;
extern void construct(Static109f20*, const Descriptor*);
extern void destroy(Static109f20*);
struct Static109f20 {
    void* value;
    Static109f20() { construct(this, &descriptor); }
    ~Static109f20() { destroy(this); }
};
