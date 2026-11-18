// Source exposure: binary-analysis
// Static8ff70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8ff70;
extern void construct(Static8ff70*, const Descriptor*);
extern void destroy(Static8ff70*);
struct Static8ff70 {
    void* value;
    Static8ff70() { construct(this, &descriptor); }
    ~Static8ff70() { destroy(this); }
};
