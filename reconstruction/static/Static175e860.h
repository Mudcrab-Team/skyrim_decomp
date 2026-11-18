// Source exposure: binary-analysis; no external implementation source reused.
// Static175e860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e860*);
    virtual void release(Static175e860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e860*);
struct Static175e860 {
    void* value;
    Static175e860();
    ~Static175e860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
