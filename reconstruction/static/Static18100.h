// Source exposure: binary-analysis
// Static18100, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static18100;
extern void construct(Static18100*, const Descriptor*);
extern void destroy(Static18100*);
struct Static18100 {
    void* value;
    Static18100() { construct(this, &descriptor); }
    ~Static18100() { destroy(this); }
};
