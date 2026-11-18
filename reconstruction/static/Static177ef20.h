// Source exposure: binary-analysis; no external implementation source reused.
// Static177ef20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ef20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ef20*);
    virtual void release(Static177ef20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ef20*);
struct Static177ef20 {
    void* value;
    Static177ef20();
    ~Static177ef20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
