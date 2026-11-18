// Source exposure: binary-analysis; no external implementation source reused.
// Static177c310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c310*);
    virtual void release(Static177c310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c310*);
struct Static177c310 {
    void* value;
    Static177c310();
    ~Static177c310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
