// Source exposure: binary-analysis; no external implementation source reused.
// Static176fed0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fed0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fed0*);
    virtual void release(Static176fed0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fed0*);
struct Static176fed0 {
    void* value;
    Static176fed0();
    ~Static176fed0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
