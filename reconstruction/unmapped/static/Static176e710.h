// Source exposure: binary-analysis; no external implementation source reused.
// Static176e710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e710*);
    virtual void release(Static176e710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e710*);
struct Static176e710 {
    void* value;
    Static176e710();
    ~Static176e710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
