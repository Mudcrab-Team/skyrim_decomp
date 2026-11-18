// Source exposure: binary-analysis; no external implementation source reused.
// Static177c270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c270*);
    virtual void release(Static177c270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c270*);
struct Static177c270 {
    void* value;
    Static177c270();
    ~Static177c270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
