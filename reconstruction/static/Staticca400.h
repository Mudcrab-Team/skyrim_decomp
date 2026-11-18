// Source exposure: binary-analysis
// Staticca400, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca400;
extern void construct(Staticca400*, const Descriptor*);
extern void destroy(Staticca400*);
struct Staticca400 {
    void* value;
    Staticca400() { construct(this, &descriptor); }
    ~Staticca400() { destroy(this); }
};
