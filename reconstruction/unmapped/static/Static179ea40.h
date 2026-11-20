// Source exposure: binary-analysis; no external implementation source reused.
// Static179ea40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ea40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ea40*);
    virtual void release(Static179ea40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ea40*);
struct Static179ea40 {
    void* value;
    Static179ea40();
    ~Static179ea40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
