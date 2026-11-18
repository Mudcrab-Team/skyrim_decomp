// Source exposure: binary-analysis; no external implementation source reused.
// Static176c870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c870*);
    virtual void release(Static176c870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c870*);
struct Static176c870 {
    void* value;
    Static176c870();
    ~Static176c870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
