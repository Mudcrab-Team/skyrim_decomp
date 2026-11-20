// Source exposure: binary-analysis
// Static97960, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97960;
extern void construct(Static97960*, const Descriptor*);
extern void destroy(Static97960*);
struct Static97960 {
    void* value;
    Static97960() { construct(this, &descriptor); }
    ~Static97960() { destroy(this); }
};
