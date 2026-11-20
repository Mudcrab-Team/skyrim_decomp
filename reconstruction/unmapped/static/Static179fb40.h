// Source exposure: binary-analysis; no external implementation source reused.
// Static179fb40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179fb40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179fb40*);
    virtual void release(Static179fb40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179fb40*);
struct Static179fb40 {
    void* value;
    Static179fb40();
    ~Static179fb40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
