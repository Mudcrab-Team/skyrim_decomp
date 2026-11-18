// Source exposure: binary-analysis; no external implementation source reused.
// Static173e690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e690*);
    virtual void release(Static173e690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e690*);
struct Static173e690 {
    void* value;
    Static173e690();
    ~Static173e690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
