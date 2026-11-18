// Source exposure: binary-analysis; no external implementation source reused.
// Static175dc30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175dc30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175dc30*);
    virtual void release(Static175dc30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175dc30*);
struct Static175dc30 {
    void* value;
    Static175dc30();
    ~Static175dc30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
