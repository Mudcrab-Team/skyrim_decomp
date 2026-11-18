// Source exposure: binary-analysis; no external implementation source reused.
// Static179e810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e810*);
    virtual void release(Static179e810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e810*);
struct Static179e810 {
    void* value;
    Static179e810();
    ~Static179e810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
