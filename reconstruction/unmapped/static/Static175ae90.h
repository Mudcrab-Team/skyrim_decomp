// Source exposure: binary-analysis; no external implementation source reused.
// Static175ae90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ae90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ae90*);
    virtual void release(Static175ae90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ae90*);
struct Static175ae90 {
    void* value;
    Static175ae90();
    ~Static175ae90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
