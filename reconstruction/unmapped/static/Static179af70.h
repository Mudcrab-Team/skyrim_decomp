// Source exposure: binary-analysis; no external implementation source reused.
// Static179af70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179af70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179af70*);
    virtual void release(Static179af70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179af70*);
struct Static179af70 {
    void* value;
    Static179af70();
    ~Static179af70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
