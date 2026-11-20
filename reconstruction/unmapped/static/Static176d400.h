// Source exposure: binary-analysis; no external implementation source reused.
// Static176d400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d400*);
    virtual void release(Static176d400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d400*);
struct Static176d400 {
    void* value;
    Static176d400();
    ~Static176d400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
