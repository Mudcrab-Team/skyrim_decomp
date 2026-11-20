// Source exposure: binary-analysis; no external implementation source reused.
// Static176fb10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fb10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fb10*);
    virtual void release(Static176fb10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fb10*);
struct Static176fb10 {
    void* value;
    Static176fb10();
    ~Static176fb10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
