// Source exposure: binary-analysis
// Static9f880, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f880;
extern void construct(Static9f880*, const Descriptor*);
extern void destroy(Static9f880*);
struct Static9f880 {
    void* value;
    Static9f880() { construct(this, &descriptor); }
    ~Static9f880() { destroy(this); }
};
