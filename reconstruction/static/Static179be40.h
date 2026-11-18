// Source exposure: binary-analysis; no external implementation source reused.
// Static179be40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179be40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179be40*);
    virtual void release(Static179be40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179be40*);
struct Static179be40 {
    void* value;
    Static179be40();
    ~Static179be40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
