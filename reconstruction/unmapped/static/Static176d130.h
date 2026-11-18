// Source exposure: binary-analysis; no external implementation source reused.
// Static176d130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d130*);
    virtual void release(Static176d130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d130*);
struct Static176d130 {
    void* value;
    Static176d130();
    ~Static176d130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
