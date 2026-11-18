// Source exposure: binary-analysis
// Static9ee40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ee40;
extern void construct(Static9ee40*, const Descriptor*);
extern void destroy(Static9ee40*);
struct Static9ee40 {
    void* value;
    Static9ee40() { construct(this, &descriptor); }
    ~Static9ee40() { destroy(this); }
};
