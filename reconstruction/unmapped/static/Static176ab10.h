// Source exposure: binary-analysis; no external implementation source reused.
// Static176ab10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ab10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ab10*);
    virtual void release(Static176ab10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ab10*);
struct Static176ab10 {
    void* value;
    Static176ab10();
    ~Static176ab10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
