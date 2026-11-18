// Source exposure: binary-analysis; no external implementation source reused.
// Static175dd20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175dd20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175dd20*);
    virtual void release(Static175dd20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175dd20*);
struct Static175dd20 {
    void* value;
    Static175dd20();
    ~Static175dd20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
