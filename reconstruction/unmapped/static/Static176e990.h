// Source exposure: binary-analysis; no external implementation source reused.
// Static176e990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e990*);
    virtual void release(Static176e990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e990*);
struct Static176e990 {
    void* value;
    Static176e990();
    ~Static176e990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
