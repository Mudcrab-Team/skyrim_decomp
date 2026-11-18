// Source exposure: binary-analysis; no external implementation source reused.
// Static179d130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d130*);
    virtual void release(Static179d130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d130*);
struct Static179d130 {
    void* value;
    Static179d130();
    ~Static179d130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
