// Source exposure: binary-analysis
// Static103610, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103610;
extern void construct(Static103610*, const Descriptor*);
extern void destroy(Static103610*);
struct Static103610 {
    void* value;
    Static103610() { construct(this, &descriptor); }
    ~Static103610() { destroy(this); }
};
