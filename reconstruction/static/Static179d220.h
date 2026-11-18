// Source exposure: binary-analysis; no external implementation source reused.
// Static179d220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d220*);
    virtual void release(Static179d220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d220*);
struct Static179d220 {
    void* value;
    Static179d220();
    ~Static179d220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
