// Source exposure: binary-analysis; no external implementation source reused.
// Static177c900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c900*);
    virtual void release(Static177c900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c900*);
struct Static177c900 {
    void* value;
    Static177c900();
    ~Static177c900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
