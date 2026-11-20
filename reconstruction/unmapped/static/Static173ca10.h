// Source exposure: binary-analysis; no external implementation source reused.
// Static173ca10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ca10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ca10*);
    virtual void release(Static173ca10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ca10*);
struct Static173ca10 {
    void* value;
    Static173ca10();
    ~Static173ca10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
