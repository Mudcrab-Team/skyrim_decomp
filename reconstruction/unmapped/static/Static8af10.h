// Source exposure: binary-analysis
// Static8af10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8af10;
extern void construct(Static8af10*, const Descriptor*);
extern void destroy(Static8af10*);
struct Static8af10 {
    void* value;
    Static8af10() { construct(this, &descriptor); }
    ~Static8af10() { destroy(this); }
};
