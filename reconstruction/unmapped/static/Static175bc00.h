// Source exposure: binary-analysis; no external implementation source reused.
// Static175bc00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bc00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bc00*);
    virtual void release(Static175bc00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bc00*);
struct Static175bc00 {
    void* value;
    Static175bc00();
    ~Static175bc00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
