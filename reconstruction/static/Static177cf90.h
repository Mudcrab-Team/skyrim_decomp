// Source exposure: binary-analysis; no external implementation source reused.
// Static177cf90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cf90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cf90*);
    virtual void release(Static177cf90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cf90*);
struct Static177cf90 {
    void* value;
    Static177cf90();
    ~Static177cf90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
