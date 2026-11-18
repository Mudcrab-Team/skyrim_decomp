// Source exposure: binary-analysis
// Static102d40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static102d40;
extern void construct(Static102d40*, const Descriptor*);
extern void destroy(Static102d40*);
struct Static102d40 {
    void* value;
    Static102d40() { construct(this, &descriptor); }
    ~Static102d40() { destroy(this); }
};
