// Source exposure: binary-analysis; no external implementation source reused.
// Static175f120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f120*);
    virtual void release(Static175f120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f120*);
struct Static175f120 {
    void* value;
    Static175f120();
    ~Static175f120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
