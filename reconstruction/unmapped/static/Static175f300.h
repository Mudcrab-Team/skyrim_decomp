// Source exposure: binary-analysis; no external implementation source reused.
// Static175f300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f300*);
    virtual void release(Static175f300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f300*);
struct Static175f300 {
    void* value;
    Static175f300();
    ~Static175f300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
