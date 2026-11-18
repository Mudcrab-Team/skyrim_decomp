// Source exposure: binary-analysis; no external implementation source reused.
// Static17588c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17588c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17588c0*);
    virtual void release(Static17588c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17588c0*);
struct Static17588c0 {
    void* value;
    Static17588c0();
    ~Static17588c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
