// Source exposure: binary-analysis; no external implementation source reused.
// Static179e660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e660*);
    virtual void release(Static179e660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e660*);
struct Static179e660 {
    void* value;
    Static179e660();
    ~Static179e660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
