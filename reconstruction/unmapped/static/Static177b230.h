// Source exposure: binary-analysis; no external implementation source reused.
// Static177b230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b230*);
    virtual void release(Static177b230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b230*);
struct Static177b230 {
    void* value;
    Static177b230();
    ~Static177b230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
