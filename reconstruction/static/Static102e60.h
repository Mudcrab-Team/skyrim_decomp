// Source exposure: binary-analysis
// Static102e60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static102e60;
extern void construct(Static102e60*, const Descriptor*);
extern void destroy(Static102e60*);
struct Static102e60 {
    void* value;
    Static102e60() { construct(this, &descriptor); }
    ~Static102e60() { destroy(this); }
};
