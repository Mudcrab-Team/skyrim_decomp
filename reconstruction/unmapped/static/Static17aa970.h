// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa970*);
    virtual void release(Static17aa970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa970*);
struct Static17aa970 {
    void* value;
    Static17aa970();
    ~Static17aa970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
