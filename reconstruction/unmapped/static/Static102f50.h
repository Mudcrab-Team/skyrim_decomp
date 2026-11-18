// Source exposure: binary-analysis
// Static102f50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static102f50;
extern void construct(Static102f50*, const Descriptor*);
extern void destroy(Static102f50*);
struct Static102f50 {
    void* value;
    Static102f50() { construct(this, &descriptor); }
    ~Static102f50() { destroy(this); }
};
