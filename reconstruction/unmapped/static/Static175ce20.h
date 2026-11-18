// Source exposure: binary-analysis; no external implementation source reused.
// Static175ce20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ce20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ce20*);
    virtual void release(Static175ce20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ce20*);
struct Static175ce20 {
    void* value;
    Static175ce20();
    ~Static175ce20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
