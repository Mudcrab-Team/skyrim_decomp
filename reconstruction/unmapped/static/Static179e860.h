// Source exposure: binary-analysis; no external implementation source reused.
// Static179e860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e860*);
    virtual void release(Static179e860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e860*);
struct Static179e860 {
    void* value;
    Static179e860();
    ~Static179e860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
