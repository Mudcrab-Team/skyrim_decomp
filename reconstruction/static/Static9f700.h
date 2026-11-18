// Source exposure: binary-analysis
// Static9f700, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f700;
extern void construct(Static9f700*, const Descriptor*);
extern void destroy(Static9f700*);
struct Static9f700 {
    void* value;
    Static9f700() { construct(this, &descriptor); }
    ~Static9f700() { destroy(this); }
};
