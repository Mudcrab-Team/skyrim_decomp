// Source exposure: binary-analysis
// Static9eb40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9eb40;
extern void construct(Static9eb40*, const Descriptor*);
extern void destroy(Static9eb40*);
struct Static9eb40 {
    void* value;
    Static9eb40() { construct(this, &descriptor); }
    ~Static9eb40() { destroy(this); }
};
