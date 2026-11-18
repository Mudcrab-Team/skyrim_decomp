// Source exposure: binary-analysis; no external implementation source reused.
// Static177ea70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ea70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ea70*);
    virtual void release(Static177ea70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ea70*);
struct Static177ea70 {
    void* value;
    Static177ea70();
    ~Static177ea70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
