// Source exposure: binary-analysis
// Static9ee10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ee10;
extern void construct(Static9ee10*, const Descriptor*);
extern void destroy(Static9ee10*);
struct Static9ee10 {
    void* value;
    Static9ee10() { construct(this, &descriptor); }
    ~Static9ee10() { destroy(this); }
};
