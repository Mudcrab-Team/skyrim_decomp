// Source exposure: binary-analysis; no external implementation source reused.
// Static173d290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d290*);
    virtual void release(Static173d290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d290*);
struct Static173d290 {
    void* value;
    Static173d290();
    ~Static173d290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
