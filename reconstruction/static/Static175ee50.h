// Source exposure: binary-analysis; no external implementation source reused.
// Static175ee50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ee50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ee50*);
    virtual void release(Static175ee50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ee50*);
struct Static175ee50 {
    void* value;
    Static175ee50();
    ~Static175ee50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
