// Source exposure: binary-analysis; no external implementation source reused.
// Static179d780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d780*);
    virtual void release(Static179d780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d780*);
struct Static179d780 {
    void* value;
    Static179d780();
    ~Static179d780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
