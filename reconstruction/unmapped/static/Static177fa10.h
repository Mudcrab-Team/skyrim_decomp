// Source exposure: binary-analysis; no external implementation source reused.
// Static177fa10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fa10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fa10*);
    virtual void release(Static177fa10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fa10*);
struct Static177fa10 {
    void* value;
    Static177fa10();
    ~Static177fa10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
