// Source exposure: binary-analysis; no external implementation source reused.
// Static179ef40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ef40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ef40*);
    virtual void release(Static179ef40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ef40*);
struct Static179ef40 {
    void* value;
    Static179ef40();
    ~Static179ef40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
