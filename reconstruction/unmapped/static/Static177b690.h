// Source exposure: binary-analysis; no external implementation source reused.
// Static177b690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b690*);
    virtual void release(Static177b690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b690*);
struct Static177b690 {
    void* value;
    Static177b690();
    ~Static177b690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
