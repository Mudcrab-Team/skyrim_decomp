// Source exposure: binary-analysis; no external implementation source reused.
// Static176e080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e080*);
    virtual void release(Static176e080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e080*);
struct Static176e080 {
    void* value;
    Static176e080();
    ~Static176e080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
