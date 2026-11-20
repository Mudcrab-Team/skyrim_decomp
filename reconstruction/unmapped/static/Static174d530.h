// Source exposure: binary-analysis; no external implementation source reused.
// Static174d530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d530*);
    virtual void release(Static174d530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d530*);
struct Static174d530 {
    void* value;
    Static174d530();
    ~Static174d530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
