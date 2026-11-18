// Source exposure: binary-analysis; no external implementation source reused.
// Static177c630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c630*);
    virtual void release(Static177c630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c630*);
struct Static177c630 {
    void* value;
    Static177c630();
    ~Static177c630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
