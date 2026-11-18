// Source exposure: binary-analysis; no external implementation source reused.
// Static177ff10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ff10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ff10*);
    virtual void release(Static177ff10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ff10*);
struct Static177ff10 {
    void* value;
    Static177ff10();
    ~Static177ff10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
