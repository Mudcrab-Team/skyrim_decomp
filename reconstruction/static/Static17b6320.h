// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6320*);
    virtual void release(Static17b6320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6320*);
struct Static17b6320 {
    void* value;
    Static17b6320();
    ~Static17b6320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
