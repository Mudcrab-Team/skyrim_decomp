// Source exposure: binary-analysis; no external implementation source reused.
// Static177bb90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bb90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bb90*);
    virtual void release(Static177bb90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bb90*);
struct Static177bb90 {
    void* value;
    Static177bb90();
    ~Static177bb90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
