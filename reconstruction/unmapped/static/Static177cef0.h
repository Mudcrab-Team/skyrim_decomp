// Source exposure: binary-analysis; no external implementation source reused.
// Static177cef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cef0*);
    virtual void release(Static177cef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cef0*);
struct Static177cef0 {
    void* value;
    Static177cef0();
    ~Static177cef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
