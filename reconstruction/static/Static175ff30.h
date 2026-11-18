// Source exposure: binary-analysis; no external implementation source reused.
// Static175ff30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ff30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ff30*);
    virtual void release(Static175ff30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ff30*);
struct Static175ff30 {
    void* value;
    Static175ff30();
    ~Static175ff30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
