// Source exposure: binary-analysis; no external implementation source reused.
// Static178aef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178aef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178aef0*);
    virtual void release(Static178aef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178aef0*);
struct Static178aef0 {
    void* value;
    Static178aef0();
    ~Static178aef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
