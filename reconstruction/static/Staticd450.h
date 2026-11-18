// Source exposure: binary-analysis
// Staticd450, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd450;
extern void construct(Staticd450*, const Descriptor*);
extern void destroy(Staticd450*);
struct Staticd450 {
    void* value;
    Staticd450() { construct(this, &descriptor); }
    ~Staticd450() { destroy(this); }
};
