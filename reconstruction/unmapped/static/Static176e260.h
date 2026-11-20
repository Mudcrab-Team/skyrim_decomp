// Source exposure: binary-analysis; no external implementation source reused.
// Static176e260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e260*);
    virtual void release(Static176e260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e260*);
struct Static176e260 {
    void* value;
    Static176e260();
    ~Static176e260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
