// Source exposure: binary-analysis; no external implementation source reused.
// Static179ce10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ce10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ce10*);
    virtual void release(Static179ce10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ce10*);
struct Static179ce10 {
    void* value;
    Static179ce10();
    ~Static179ce10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
