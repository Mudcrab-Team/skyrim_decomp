// Source exposure: binary-analysis
// Static108960, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108960;
extern void construct(Static108960*, const Descriptor*);
extern void destroy(Static108960*);
struct Static108960 {
    void* value;
    Static108960() { construct(this, &descriptor); }
    ~Static108960() { destroy(this); }
};
