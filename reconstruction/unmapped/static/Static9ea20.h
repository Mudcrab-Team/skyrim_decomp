// Source exposure: binary-analysis
// Static9ea20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ea20;
extern void construct(Static9ea20*, const Descriptor*);
extern void destroy(Static9ea20*);
struct Static9ea20 {
    void* value;
    Static9ea20() { construct(this, &descriptor); }
    ~Static9ea20() { destroy(this); }
};
