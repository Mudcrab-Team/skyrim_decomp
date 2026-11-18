// Source exposure: binary-analysis; no external implementation source reused.
// Static1771690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771690*);
    virtual void release(Static1771690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771690*);
struct Static1771690 {
    void* value;
    Static1771690();
    ~Static1771690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
