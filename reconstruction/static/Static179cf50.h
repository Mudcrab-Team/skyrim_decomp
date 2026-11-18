// Source exposure: binary-analysis; no external implementation source reused.
// Static179cf50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179cf50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179cf50*);
    virtual void release(Static179cf50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179cf50*);
struct Static179cf50 {
    void* value;
    Static179cf50();
    ~Static179cf50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
