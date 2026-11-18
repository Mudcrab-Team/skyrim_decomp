// Source exposure: binary-analysis; no external implementation source reused.
// Static179af20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179af20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179af20*);
    virtual void release(Static179af20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179af20*);
struct Static179af20 {
    void* value;
    Static179af20();
    ~Static179af20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
