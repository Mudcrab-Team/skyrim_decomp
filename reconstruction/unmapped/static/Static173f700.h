// Source exposure: binary-analysis; no external implementation source reused.
// Static173f700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f700*);
    virtual void release(Static173f700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f700*);
struct Static173f700 {
    void* value;
    Static173f700();
    ~Static173f700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
