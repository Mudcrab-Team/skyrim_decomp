// Source exposure: binary-analysis; no external implementation source reused.
// Static176c820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c820*);
    virtual void release(Static176c820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c820*);
struct Static176c820 {
    void* value;
    Static176c820();
    ~Static176c820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
