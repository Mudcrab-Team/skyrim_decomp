// Source exposure: binary-analysis; no external implementation source reused.
// Static175cf10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cf10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cf10*);
    virtual void release(Static175cf10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cf10*);
struct Static175cf10 {
    void* value;
    Static175cf10();
    ~Static175cf10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
