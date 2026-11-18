// Source exposure: binary-analysis; no external implementation source reused.
// Static175ec20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ec20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ec20*);
    virtual void release(Static175ec20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ec20*);
struct Static175ec20 {
    void* value;
    Static175ec20();
    ~Static175ec20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
