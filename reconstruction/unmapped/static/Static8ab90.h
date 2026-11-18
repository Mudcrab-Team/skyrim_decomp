// Source exposure: binary-analysis
// Static8ab90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8ab90;
extern void construct(Static8ab90*, const Descriptor*);
extern void destroy(Static8ab90*);
struct Static8ab90 {
    void* value;
    Static8ab90() { construct(this, &descriptor); }
    ~Static8ab90() { destroy(this); }
};
