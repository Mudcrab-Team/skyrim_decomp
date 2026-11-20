// Source exposure: binary-analysis
// Static102f20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static102f20;
extern void construct(Static102f20*, const Descriptor*);
extern void destroy(Static102f20*);
struct Static102f20 {
    void* value;
    Static102f20() { construct(this, &descriptor); }
    ~Static102f20() { destroy(this); }
};
