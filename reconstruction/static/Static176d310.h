// Source exposure: binary-analysis; no external implementation source reused.
// Static176d310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d310*);
    virtual void release(Static176d310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d310*);
struct Static176d310 {
    void* value;
    Static176d310();
    ~Static176d310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
