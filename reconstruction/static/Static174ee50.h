// Source exposure: binary-analysis; no external implementation source reused.
// Static174ee50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ee50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ee50*);
    virtual void release(Static174ee50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ee50*);
struct Static174ee50 {
    void* value;
    Static174ee50();
    ~Static174ee50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
