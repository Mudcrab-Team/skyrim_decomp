// Source exposure: binary-analysis; no external implementation source reused.
// Static176f570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f570*);
    virtual void release(Static176f570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f570*);
struct Static176f570 {
    void* value;
    Static176f570();
    ~Static176f570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
