// Source exposure: binary-analysis; no external implementation source reused.
// Static176c500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c500*);
    virtual void release(Static176c500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c500*);
struct Static176c500 {
    void* value;
    Static176c500();
    ~Static176c500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
