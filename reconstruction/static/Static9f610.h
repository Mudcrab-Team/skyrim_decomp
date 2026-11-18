// Source exposure: binary-analysis
// Static9f610, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f610;
extern void construct(Static9f610*, const Descriptor*);
extern void destroy(Static9f610*);
struct Static9f610 {
    void* value;
    Static9f610() { construct(this, &descriptor); }
    ~Static9f610() { destroy(this); }
};
