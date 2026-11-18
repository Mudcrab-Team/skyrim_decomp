// Source exposure: binary-analysis; no external implementation source reused.
// Static175f800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f800*);
    virtual void release(Static175f800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f800*);
struct Static175f800 {
    void* value;
    Static175f800();
    ~Static175f800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
