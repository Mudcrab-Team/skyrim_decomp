// Source exposure: binary-analysis; no external implementation source reused.
// Static179c520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c520*);
    virtual void release(Static179c520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c520*);
struct Static179c520 {
    void* value;
    Static179c520();
    ~Static179c520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
