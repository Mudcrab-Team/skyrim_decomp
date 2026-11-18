// Source exposure: binary-analysis; no external implementation source reused.
// Static178d740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d740*);
    virtual void release(Static178d740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d740*);
struct Static178d740 {
    void* value;
    Static178d740();
    ~Static178d740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
