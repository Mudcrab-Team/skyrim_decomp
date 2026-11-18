// Source exposure: binary-analysis
// Static8bc90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8bc90;
extern void construct(Static8bc90*, const Descriptor*);
extern void destroy(Static8bc90*);
struct Static8bc90 {
    void* value;
    Static8bc90() { construct(this, &descriptor); }
    ~Static8bc90() { destroy(this); }
};
