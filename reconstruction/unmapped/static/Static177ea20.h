// Source exposure: binary-analysis; no external implementation source reused.
// Static177ea20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ea20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ea20*);
    virtual void release(Static177ea20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ea20*);
struct Static177ea20 {
    void* value;
    Static177ea20();
    ~Static177ea20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
