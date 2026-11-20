// Source exposure: binary-analysis
// Static8ff10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8ff10;
extern void construct(Static8ff10*, const Descriptor*);
extern void destroy(Static8ff10*);
struct Static8ff10 {
    void* value;
    Static8ff10() { construct(this, &descriptor); }
    ~Static8ff10() { destroy(this); }
};
