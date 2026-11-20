// Source exposure: binary-analysis; no external implementation source reused.
// Static174ef40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ef40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ef40*);
    virtual void release(Static174ef40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ef40*);
struct Static174ef40 {
    void* value;
    Static174ef40();
    ~Static174ef40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
