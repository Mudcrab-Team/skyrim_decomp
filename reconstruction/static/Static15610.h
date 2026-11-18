// Source exposure: binary-analysis
// Static15610, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15610;
extern void construct(Static15610*, const Descriptor*);
extern void destroy(Static15610*);
struct Static15610 {
    void* value;
    Static15610() { construct(this, &descriptor); }
    ~Static15610() { destroy(this); }
};
