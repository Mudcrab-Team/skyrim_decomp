// Source exposure: binary-analysis
// Static8b000, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b000;
extern void construct(Static8b000*, const Descriptor*);
extern void destroy(Static8b000*);
struct Static8b000 {
    void* value;
    Static8b000() { construct(this, &descriptor); }
    ~Static8b000() { destroy(this); }
};
