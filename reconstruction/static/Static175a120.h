// Source exposure: binary-analysis; no external implementation source reused.
// Static175a120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a120*);
    virtual void release(Static175a120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a120*);
struct Static175a120 {
    void* value;
    Static175a120();
    ~Static175a120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
