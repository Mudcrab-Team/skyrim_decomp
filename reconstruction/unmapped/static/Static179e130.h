// Source exposure: binary-analysis; no external implementation source reused.
// Static179e130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e130*);
    virtual void release(Static179e130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e130*);
struct Static179e130 {
    void* value;
    Static179e130();
    ~Static179e130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
