// Source exposure: binary-analysis; no external implementation source reused.
// Static176a700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a700*);
    virtual void release(Static176a700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a700*);
struct Static176a700 {
    void* value;
    Static176a700();
    ~Static176a700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
