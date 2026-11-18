// Source exposure: binary-analysis
// Static102e90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static102e90;
extern void construct(Static102e90*, const Descriptor*);
extern void destroy(Static102e90*);
struct Static102e90 {
    void* value;
    Static102e90() { construct(this, &descriptor); }
    ~Static102e90() { destroy(this); }
};
