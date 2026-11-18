// Source exposure: binary-analysis; no external implementation source reused.
// Static176c730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c730*);
    virtual void release(Static176c730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c730*);
struct Static176c730 {
    void* value;
    Static176c730();
    ~Static176c730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
