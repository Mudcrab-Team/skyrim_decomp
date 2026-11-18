// Source exposure: binary-analysis; no external implementation source reused.
// Static175a800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a800*);
    virtual void release(Static175a800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a800*);
struct Static175a800 {
    void* value;
    Static175a800();
    ~Static175a800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
