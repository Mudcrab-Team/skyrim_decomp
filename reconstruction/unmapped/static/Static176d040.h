// Source exposure: binary-analysis; no external implementation source reused.
// Static176d040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d040*);
    virtual void release(Static176d040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d040*);
struct Static176d040 {
    void* value;
    Static176d040();
    ~Static176d040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
