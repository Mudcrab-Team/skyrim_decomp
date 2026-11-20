// Source exposure: binary-analysis; no external implementation source reused.
// Static179d310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d310*);
    virtual void release(Static179d310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d310*);
struct Static179d310 {
    void* value;
    Static179d310();
    ~Static179d310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
