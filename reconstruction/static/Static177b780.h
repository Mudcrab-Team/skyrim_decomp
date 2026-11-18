// Source exposure: binary-analysis; no external implementation source reused.
// Static177b780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b780*);
    virtual void release(Static177b780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b780*);
struct Static177b780 {
    void* value;
    Static177b780();
    ~Static177b780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
