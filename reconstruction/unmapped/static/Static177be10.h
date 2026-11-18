// Source exposure: binary-analysis; no external implementation source reused.
// Static177be10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177be10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177be10*);
    virtual void release(Static177be10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177be10*);
struct Static177be10 {
    void* value;
    Static177be10();
    ~Static177be10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
