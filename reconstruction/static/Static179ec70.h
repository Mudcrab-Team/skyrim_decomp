// Source exposure: binary-analysis; no external implementation source reused.
// Static179ec70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ec70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ec70*);
    virtual void release(Static179ec70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ec70*);
struct Static179ec70 {
    void* value;
    Static179ec70();
    ~Static179ec70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
