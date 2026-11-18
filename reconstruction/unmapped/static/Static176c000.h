// Source exposure: binary-analysis; no external implementation source reused.
// Static176c000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c000*);
    virtual void release(Static176c000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c000*);
struct Static176c000 {
    void* value;
    Static176c000();
    ~Static176c000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
