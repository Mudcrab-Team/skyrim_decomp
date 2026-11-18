// Source exposure: binary-analysis
// Static8700, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8700;
extern void construct(Static8700*, const Descriptor*);
extern void destroy(Static8700*);
struct Static8700 {
    void* value;
    Static8700() { construct(this, &descriptor); }
    ~Static8700() { destroy(this); }
};
