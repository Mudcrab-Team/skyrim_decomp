// Source exposure: binary-analysis; no external implementation source reused.
// Static175ab20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ab20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ab20*);
    virtual void release(Static175ab20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ab20*);
struct Static175ab20 {
    void* value;
    Static175ab20();
    ~Static175ab20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
