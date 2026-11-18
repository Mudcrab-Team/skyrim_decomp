// Source exposure: binary-analysis; no external implementation source reused.
// Static179c660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c660*);
    virtual void release(Static179c660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c660*);
struct Static179c660 {
    void* value;
    Static179c660();
    ~Static179c660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
