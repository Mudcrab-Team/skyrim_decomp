// Source exposure: binary-analysis
// Static99e90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static99e90;
extern void construct(Static99e90*, const Descriptor*);
extern void destroy(Static99e90*);
struct Static99e90 {
    void* value;
    Static99e90() { construct(this, &descriptor); }
    ~Static99e90() { destroy(this); }
};
