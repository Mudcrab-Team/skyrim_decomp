// Source exposure: binary-analysis; no external implementation source reused.
// Static175bc50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bc50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bc50*);
    virtual void release(Static175bc50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bc50*);
struct Static175bc50 {
    void* value;
    Static175bc50();
    ~Static175bc50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
