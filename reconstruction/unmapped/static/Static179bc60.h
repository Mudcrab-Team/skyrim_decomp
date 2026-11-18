// Source exposure: binary-analysis; no external implementation source reused.
// Static179bc60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179bc60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179bc60*);
    virtual void release(Static179bc60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179bc60*);
struct Static179bc60 {
    void* value;
    Static179bc60();
    ~Static179bc60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
