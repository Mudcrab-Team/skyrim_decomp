// Source exposure: binary-analysis; no external implementation source reused.
// Static179de90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179de90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179de90*);
    virtual void release(Static179de90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179de90*);
struct Static179de90 {
    void* value;
    Static179de90();
    ~Static179de90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
