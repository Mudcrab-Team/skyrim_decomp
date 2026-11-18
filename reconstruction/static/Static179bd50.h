// Source exposure: binary-analysis; no external implementation source reused.
// Static179bd50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179bd50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179bd50*);
    virtual void release(Static179bd50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179bd50*);
struct Static179bd50 {
    void* value;
    Static179bd50();
    ~Static179bd50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
